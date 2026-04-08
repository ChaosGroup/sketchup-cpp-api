require 'testup/testcase'
require "#{__dir__}/TestRubyClass"

module TestUp
module Tests
    # Set of tests triggering different result types.
    class TC_TestRubyUtils_RubyClass_get_class < TestUp::TestCase
        include RubyUtils_Tests::RubyClass::Get_class
    end
end
end
