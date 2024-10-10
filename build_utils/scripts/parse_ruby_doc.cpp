#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

std::string class_name;

struct method {
    std::string ruby_name;
    std::vector<std::string> params;
    std::map<std::string, std::string> param_types;
    std::map<std::string, std::string> default_values;
    std::string return_type;
    std::string return_comment;
    std::string cpp_comments;
    std::string notes;
    std::string min_su_version;
    
    std::string cpp_name() const {
        if (ruby_name.back() == '=') {
            return "set_"  + ruby_name.substr(0, ruby_name.size() - 1);
        }
        if (ruby_name.back() == '?') {
            return "is_" + ruby_name.substr(0, ruby_name.size() - 1);
        }
        if (ruby_name == "[]") {
            return "operator[]";
        }
        return ruby_name;
    }

    static std::string cpp_type(std::string type) {
        if (type.back() == '?') return "RubyUtils::optional<" + cpp_type(type.substr(0, type.size() - 1)) + ">";
        if (type.substr(0, 6) == "Array<") return "RubyUtils::Enumerable<" + cpp_type(type.substr(6, type.size() - 7)) + ">";
        if (type == "String") return "std::string";
        if (type == "Boolean") return "bool";
        if (type == "Integer") return "long long";
        if (type == "Float") return "double";
        if (type == "Numeric") return "double";
        if (type == "nil") return "void";
        if (type == "Object") return "RubyUtils::details::IObject";
        if (type.find(",") != std::string::npos) {
            std::string answer;
            std::vector<std::string> types;
            std::string current_type = "";
            bool optional = false;
            for (size_t i = 0 ; i < type.size() ; i ++)
            {
                const char x = type[i];
                if (x == ' ') continue;
                if (x == ',')
                {
                    if (current_type == "nil") optional = true;
                    else types.push_back(current_type);
                    current_type = "";
                }
                else
                {
                    current_type += x;
                }
            }
            if (current_type.size() != 0)
            {
                if (current_type == "nil") optional = true;
                else types.push_back(current_type);
            }
            if (optional) answer += "RubyUtils::optional<";
            if (types.size() > 1) answer += "RubyUtils::any_of<";
            for (size_t i = 0 ; i < types.size() - 1 ; i ++)
                answer += cpp_type(types[i]) + ", ";
            answer += cpp_type(types.back());
            if (types.size() > 1) answer += ">";
            if (optional) answer += ">";
            return answer;
        }
        return type;
    }

    static std::string ruby_name_to_url(std::string ruby_name) {
        if (ruby_name.back() == '?') return ruby_name.substr(0, ruby_name.size() - 1) + "%3F";
        return ruby_name;
    }

    void fix() {
        return_type = cpp_type(return_type);
        for (auto& x : param_types) x.second = cpp_type(x.second);

        std::string url = "https://ruby.sketchup.com/Sketchup/" + class_name + ".html#" + ruby_name_to_url(ruby_name) + "-instance_method";
        cpp_comments = R"(/**
* @brief )" + url + R"(
* 
)";
        for (auto param : params) {
            cpp_comments += "* @param " + param + " read " + url + "\n";
        }
        cpp_comments += R"(* @return )" + return_type + R"( read )" + url + R"(
* @min_version )" + min_su_version + R"(
*/)";
    }

    friend std::ostream& operator<< (std::ostream& out, method& m) {
        m.fix();
        out << m.cpp_comments << std::endl;
        if (m.params.size() == 0) {
            out << "DEFINE_WRAPPED_METHOD_0(" << m.return_type << ", " << m.cpp_name() << ", " << m.ruby_name << ")";
        }
        else {
            out << "DEFINE_WRAPPED_METHOD(" << m.return_type << ", " << m.cpp_name() << ", (";
            bool is_first = true;
            for (auto param : m.params) {
                if (!is_first) out << ", ";
                else is_first = false;
                out << m.param_types[param] << " " << param;
                if (m.default_values.find(param) != m.default_values.end()) out << " = " << m.default_values[param];
            }
            out << "), " << m.ruby_name << ", ";
            is_first = true;
            for (auto param : m.params) {
                if (!is_first) out << ", ";
                else is_first = false;
                out << param;
            }
            out << ")";
        }
        return out;
    }
};

//        signature
std::map<std::string, method> methods;

bool is_letter(wchar_t c) {
    return 'a' <= c && c <= 'z';
} 

enum parse_status {
    FILLER,
    METHOD_DECLARATION,
    METHOD_PARAMETERS,
    METHOD_OVERLOADS,
    METHOD_VERSION,
    METHOD_EXAMPLES,
    METHOD_RAISES,
    METHOD_RETURNS,
    SEE_ALSO
};

void read_line(std::istream& in, std::string& line, parse_status& status) {
    line = "";
    while (!in.eof() && line.size() == 0)
        std::getline(in, line);
    if (line == "Parameters:") {
        status = parse_status::METHOD_PARAMETERS;
        read_line(in, line, status);
    }
    else if (line == "Overloads:") {
        status = parse_status::METHOD_OVERLOADS;
        read_line(in, line, status);
    }
    else if (line == "Version:") {
        status = parse_status::METHOD_VERSION;
        read_line(in, line, status);
    }
    else if (line == "Returns:") {
        status = parse_status::METHOD_RETURNS;
        read_line(in, line, status);
    }
    else if (line == "Examples:") {
        status = parse_status::METHOD_EXAMPLES;
        read_line(in, line, status);
    }
    else if (line == "See Also:") {
        status = parse_status::SEE_ALSO;
        read_line(in, line, status);
    }
    else if (line == "Raises:") {
        status = parse_status::METHOD_RAISES;
        read_line(in, line, status);
    }
    else if (line[0] == '$') status = parse_status::METHOD_DECLARATION;
    else if (line[0] == '#' && line.find('@') != std::string::npos) status = parse_status::METHOD_DECLARATION;
    else if (line == "Instance Method Details") status = parse_status::FILLER;
}

int main(int args, char** argv) {
    std::ifstream in;
    std::string parsed_file = std::string(argv[1]);
    in.open(argv[1]);
    std::ofstream out;
    std::string output_dir = OUTPUT_DIR;
    std::string output_file = std::string(argv[1]);
    output_file = output_dir + output_file.substr(0, output_file.size() - 2) + "hpp";
    out.open(output_file);
    class_name = parsed_file.substr(0, parsed_file.size() - 3);
    std::string latest_method_signature;
    parse_status status = parse_status::FILLER;
    std::string line;
    while (!in.eof()) {
        // std::cout << status << " " << line << std::endl;
        if (status == parse_status::FILLER) {
            while (status == parse_status::FILLER && !in.eof()) {
                read_line(in, line, status);
            }
        }
        else if (status == parse_status::SEE_ALSO) {
            while (status == parse_status::SEE_ALSO && !in.eof()) {
                read_line(in, line, status);
            }
        }
        else if (status == parse_status::METHOD_RETURNS) {
            while (status == parse_status::METHOD_RETURNS && !in.eof()) {
                read_line(in, line, status);
            }
        }
        else if (status == parse_status::METHOD_EXAMPLES) {
            while (status == parse_status::METHOD_EXAMPLES && !in.eof()) {
                read_line(in, line, status);
            }
        }
        else if (status == parse_status::METHOD_RAISES) {
            while (status == parse_status::METHOD_RAISES && !in.eof()) {
                read_line(in, line, status);
            }
        }
        else if (status == parse_status::METHOD_VERSION) {
            while (!in.eof() && status == parse_status::METHOD_VERSION) {
                methods[latest_method_signature].min_su_version += line;
                read_line(in, line, status);
            }
        }
        else if (status == parse_status::METHOD_PARAMETERS) {
            while(!in.eof() && status == parse_status::METHOD_PARAMETERS) {
                std::cout << latest_method_signature << std::endl;
                std::string param_name;
                size_t i;
                for (i = 0 ; i < line.size() && line[i] != ' ' ; i ++)
                    param_name += line[i];
                std::cout << "\tparam_name " << param_name << std::endl;
                if (i >= line.size() || line[i] != ' ') {
                    status = parse_status::FILLER;
                    read_line(in, line, status);
                    continue;
                }
                i ++; // skip the ' '
                if (i >= line.size() || line[i] != '(') {
                    read_line(in, line, status);
                    continue;
                }
                i ++; // skip the '('
                std::string param_type;
                for ( ; i < line.size() && line[i] != ')' ; i ++)
                    param_type += line[i];
                std::cout << "\toriginal param_type " << param_type << std::endl;
                if (param_type.size() == 0) param_type = "Object";
                std::cout << "\t\tparsed param_type " << param_type << std::endl;
                methods[latest_method_signature].param_types[param_name] = param_type;
                read_line(in, line, status);
            }
        }
        else if (status == parse_status::METHOD_DECLARATION || status == parse_status::METHOD_OVERLOADS) { // new method(s)
            latest_method_signature = line.substr(line[0] == '$');
            // std::cout << "METHOD_DECLARATION: " << latest_method_signature << std::endl;
            if (latest_method_signature.size() == 0)
            {
                read_line(in, line, status);
                continue;
            }
            size_t i;
            std::string method_name;
            for (i = (line[0] == '$') + 1 ; line[i] != ' ' && line[i] != '(' ; i ++) {
                method_name += line[i];
            }
            std::cout << "method_name: " << method_name << std::endl;
            auto it = methods.find(latest_method_signature);
            if (it != methods.end())
                methods.erase(it);
            methods[latest_method_signature].ruby_name = method_name;
            if (line[i] == '(') { // has params
                std::cout << "has_params: " << latest_method_signature << std::endl;
                std::string param_name;
                std::string default_value;
                bool is_param_name = true;
                for (i++ ; line[i-1] != ')' ; i++) {
                    if ((line[i] == ' ' || line[i] == ')') && is_param_name) {
                        std::cout << "\tparam because of '" << line[i] << "': " << param_name << std::endl;
                        methods[latest_method_signature].params.push_back(param_name);
                        is_param_name = false;
                    }
                    else if (line[i] == ',') {
                        if (default_value.size() != 0) {
                            // std::cout << "\t\tdefault: " << default_value << std::endl;
                            methods[latest_method_signature].default_values[param_name] = default_value;
                        }
                        else {
                            std::cout << "\tparam with no default_value: " << param_name << std::endl;
                            methods[latest_method_signature].params.push_back(param_name);
                        }
                        param_name = "";
                        default_value = "";
                        is_param_name = true;
                        i ++; // skip the ' '
                    }
                    else if (line[i] == '=') {
                        i ++; // skip ' '
                    }
                    else {
                        if (is_param_name) param_name += line[i];
                        else default_value += line[i];
                    }
                }
            }
            for ( ; line[i] != '@' ; i ++) {}
            i ++; // skip ' '
            std::string ret_type;
            for (i ++ ; i < line.size() ; i ++)
                ret_type += line[i];
            methods[latest_method_signature].return_type = ret_type;
            status = parse_status::FILLER;
            read_line(in, line, status);
        }
    }
    for (auto& x : methods) {
        out << x.second << std::endl << std::endl;
    }
}