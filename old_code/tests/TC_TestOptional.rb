require 'testup/testcase'
require "#{__dir__}/TestOptional"

module TestUp
module Tests
    # Set of tests triggering different result types.
    class TC_TestRubyUtils_optional < TestUp::TestCase
        include RubyUtils_Tests::Optional
    end
end
end
