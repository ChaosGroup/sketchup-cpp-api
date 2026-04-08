module Sketchup

  # Class Methods

  # The active_model method returns the currently active SketchUp model. On the
  # PC, this is the only model that one can have access to via the API, but
  # Macintosh versions of SketchUp can have multiple models open at once, in
  # which case the method will return the model that the user currently has
  # focused.
  #
  # @example
  #   model = Sketchup.active_model
  #   if !model
  #     puts "Failure"
  #   else
  #     # code acting on the model
  #   end
  #
  # @return [Sketchup::Model, nil] active model object if successful, false if
  #   unsuccessful
  #
  # @version SketchUp 6.0
  def self.active_model
  end

  # Setter methods that return nil, not String as the stubs claim.

  # @return [nil]
  def self.status_text=(status_text)
  end

  # @return [nil]
  def self.vcb_label=(label_text)
  end

  # @return [nil]
  def self.vcb_value=(value)
  end

  # The stubs say @return [String] but it actually returns a boolean.
  # @return [Boolean]
  def self.template=(filename)
  end

end