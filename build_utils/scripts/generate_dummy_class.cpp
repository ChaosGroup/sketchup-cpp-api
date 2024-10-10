#include <fstream>

int main(int args, char** argv) {
    std::ofstream out (SOURCE_DIR, std::ios::app);
    for (int i = 1 ; i < args ; i ++) {
        const std::string class_name = argv[i];
        out << "class " << class_name << R"( : public RubyUtils::details::IObject {
    public:
        )" << class_name << R"((VALUE obj) : IObject(obj) { }
        )" << class_name << R"((const IObject& obj) : IObject(obj) { }
};

)";
    }
}