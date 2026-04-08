require 'testup/testcase'
require "#{__dir__}/TestObject"

module TestUp
module Tests
    # Set of tests triggering different result types.
    class TC_TestRubyUtils_Object_Is_a_klass_Material < TestUp::TestCase
        include RubyUtils_Object_Is_a_klass::Material
    end

    class TC_TestRubyUtils_Object_Is_a_klass_Materials < TestUp::TestCase
        include RubyUtils_Object_Is_a_klass::Materials
    end

    class TC_TestRubyUtils_Object_Is_a_klass_Model < TestUp::TestCase
        include RubyUtils_Object_Is_a_klass::Model
    end
end
end
