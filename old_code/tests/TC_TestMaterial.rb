require 'testup/testcase'
require "#{__dir__}/TestMaterial"

module TestUp
module Tests
    # Set of tests triggering different result types.
    class TC_TestSketchup_Material < TestUp::TestCase
        include Sketchup_Tests::Material
    end
end
end
