/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 3.2.0

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "EnvPanel.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
EnvPanel::EnvPanel (SynthParams &p)
    : PanelBase(p),
      envVol(p.envVol[0])
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (attackTime = new MouseOverKnob ("Attack Time"));
    attackTime->setRange (0.001, 5, 0);
    attackTime->setSliderStyle (Slider::RotaryVerticalDrag);
    attackTime->setTextBoxStyle (Slider::TextBoxBelow, false, 56, 20);
    attackTime->setColour (Slider::rotarySliderFillColourId, Colour (0xffbfa65a));
    attackTime->setColour (Slider::textBoxTextColourId, Colours::white);
    attackTime->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    attackTime->setColour (Slider::textBoxOutlineColourId, Colour (0x00ffffff));
    attackTime->addListener (this);
    attackTime->setSkewFactor (0.5);

    addAndMakeVisible (decayTime = new MouseOverKnob ("Decay Time"));
    decayTime->setRange (0.001, 5, 0);
    decayTime->setSliderStyle (Slider::RotaryVerticalDrag);
    decayTime->setTextBoxStyle (Slider::TextBoxBelow, false, 56, 20);
    decayTime->setColour (Slider::rotarySliderFillColourId, Colour (0xffbfa65a));
    decayTime->setColour (Slider::textBoxTextColourId, Colours::white);
    decayTime->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    decayTime->setColour (Slider::textBoxOutlineColourId, Colour (0x00ffffff));
    decayTime->addListener (this);
    decayTime->setSkewFactor (0.5);

    addAndMakeVisible (sustainLevel = new MouseOverKnob ("Sustain"));
    sustainLevel->setRange (-96, 0, 0);
    sustainLevel->setSliderStyle (Slider::RotaryVerticalDrag);
    sustainLevel->setTextBoxStyle (Slider::TextBoxBelow, false, 56, 20);
    sustainLevel->setColour (Slider::rotarySliderFillColourId, Colour (0xffbfa65a));
    sustainLevel->setColour (Slider::textBoxTextColourId, Colours::white);
    sustainLevel->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    sustainLevel->setColour (Slider::textBoxOutlineColourId, Colour (0x00ffffff));
    sustainLevel->addListener (this);
    sustainLevel->setSkewFactor (3);

    addAndMakeVisible (releaseTime = new MouseOverKnob ("Release Time"));
    releaseTime->setRange (0.001, 5, 0);
    releaseTime->setSliderStyle (Slider::RotaryVerticalDrag);
    releaseTime->setTextBoxStyle (Slider::TextBoxBelow, false, 56, 20);
    releaseTime->setColour (Slider::rotarySliderFillColourId, Colour (0xffbfa65a));
    releaseTime->setColour (Slider::textBoxTextColourId, Colours::white);
    releaseTime->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    releaseTime->setColour (Slider::textBoxOutlineColourId, Colour (0x00ffffff));
    releaseTime->addListener (this);
    releaseTime->setSkewFactor (0.5);

    addAndMakeVisible (attackShape = new MouseOverKnob ("Attack Shape"));
    attackShape->setRange (0.01, 10, 0);
    attackShape->setSliderStyle (Slider::RotaryVerticalDrag);
    attackShape->setTextBoxStyle (Slider::NoTextBox, false, 0, 0);
    attackShape->setColour (Slider::rotarySliderFillColourId, Colours::white);
    attackShape->addListener (this);
    attackShape->setSkewFactor (0.3);

    addAndMakeVisible (decayShape = new MouseOverKnob ("Decay Shape"));
    decayShape->setRange (0.01, 10, 0);
    decayShape->setSliderStyle (Slider::RotaryVerticalDrag);
    decayShape->setTextBoxStyle (Slider::NoTextBox, false, 0, 0);
    decayShape->setColour (Slider::rotarySliderFillColourId, Colours::white);
    decayShape->addListener (this);
    decayShape->setSkewFactor (0.3);

    addAndMakeVisible (releaseShape = new MouseOverKnob ("Release Shape"));
    releaseShape->setRange (0.01, 10, 0);
    releaseShape->setSliderStyle (Slider::RotaryVerticalDrag);
    releaseShape->setTextBoxStyle (Slider::NoTextBox, false, 0, 0);
    releaseShape->setColour (Slider::rotarySliderFillColourId, Colours::white);
    releaseShape->addListener (this);
    releaseShape->setSkewFactor (0.3);

    addAndMakeVisible (speedMod1 = new MouseOverKnob ("speedMod1"));
    speedMod1->setRange (0, 8, 0);
    speedMod1->setSliderStyle (Slider::RotaryVerticalDrag);
    speedMod1->setTextBoxStyle (Slider::TextBoxBelow, true, 0, 0);
    speedMod1->setColour (Slider::rotarySliderFillColourId, Colours::white);
    speedMod1->setColour (Slider::textBoxTextColourId, Colours::white);
    speedMod1->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    speedMod1->setColour (Slider::textBoxOutlineColourId, Colour (0x00ffffff));
    speedMod1->addListener (this);

    addAndMakeVisible (envelopeCurve = new EnvelopeCurve (envVol.attack.get(), envVol.decay.get(), envVol.sustain.get(), envVol.release.get(),  envVol.attackShape.get(), envVol.decayShape.get(), envVol.releaseShape.get()
                                                          ));
    envelopeCurve->setName ("Envelope Curve");

    addAndMakeVisible (shapeLabel1 = new Label ("new label",
                                                TRANS("shape")));
    shapeLabel1->setFont (Font ("Bauhaus LightA", 20.00f, Font::plain));
    shapeLabel1->setJustificationType (Justification::centred);
    shapeLabel1->setEditable (false, false, false);
    shapeLabel1->setColour (Label::textColourId, Colours::white);
    shapeLabel1->setColour (TextEditor::textColourId, Colours::black);
    shapeLabel1->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (envSpeedModSrc2 = new ModSourceBox ("envSpeedModSrcBox2"));
    envSpeedModSrc2->setEditableText (false);
    envSpeedModSrc2->setJustificationType (Justification::centred);
    envSpeedModSrc2->setTextWhenNothingSelected (TRANS("No Mod"));
    envSpeedModSrc2->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    envSpeedModSrc2->addListener (this);

    addAndMakeVisible (envSpeedModSrc1 = new ModSourceBox ("envSpeedModSrcBox1"));
    envSpeedModSrc1->setEditableText (false);
    envSpeedModSrc1->setJustificationType (Justification::centred);
    envSpeedModSrc1->setTextWhenNothingSelected (TRANS("No Mod"));
    envSpeedModSrc1->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    envSpeedModSrc1->addListener (this);

    addAndMakeVisible (speedMod2 = new MouseOverKnob ("speedMod2"));
    speedMod2->setRange (0, 8, 0);
    speedMod2->setSliderStyle (Slider::RotaryVerticalDrag);
    speedMod2->setTextBoxStyle (Slider::TextBoxBelow, true, 0, 0);
    speedMod2->setColour (Slider::rotarySliderFillColourId, Colours::white);
    speedMod2->setColour (Slider::textBoxTextColourId, Colours::white);
    speedMod2->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    speedMod2->setColour (Slider::textBoxOutlineColourId, Colour (0x00ffffff));
    speedMod2->addListener (this);

    addAndMakeVisible (speedModLabel = new Label ("new label",
                                                  TRANS("speed mod")));
    speedModLabel->setFont (Font ("Bauhaus LightA", 20.00f, Font::plain));
    speedModLabel->setJustificationType (Justification::centred);
    speedModLabel->setEditable (false, false, false);
    speedModLabel->setColour (Label::textColourId, Colours::white);
    speedModLabel->setColour (TextEditor::textColourId, Colours::black);
    speedModLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]
    registerSlider(attackTime, &envVol.attack, std::bind(&EnvPanel::updateCurve, this));
    registerSlider(decayTime, &envVol.decay, std::bind(&EnvPanel::updateCurve, this));
    registerSlider(sustainLevel, &envVol.sustain, std::bind(&EnvPanel::updateCurve, this));
    registerSlider(releaseTime, &envVol.release, std::bind(&EnvPanel::updateCurve, this));
    registerSlider(attackShape, &envVol.attackShape, std::bind(&EnvPanel::updateCurve, this));
    registerSlider(decayShape, &envVol.decayShape, std::bind(&EnvPanel::updateCurve, this));
    registerSlider(releaseShape, &envVol.releaseShape, std::bind(&EnvPanel::updateCurve, this));
    registerSlider(speedMod1, &envVol.speedModAmount1);
    registerSlider(speedMod2, &envVol.speedModAmount2);

    fillModsourceBox(envSpeedModSrc1, true);
    fillModsourceBox(envSpeedModSrc2, true);

    registerSaturnSource(attackTime, speedMod1, &envVol.speedModSrc1, &envVol.speedModAmount1, 1, MouseOverKnob::modAmountConversion::percentage);
    registerSaturnSource(attackTime, speedMod2, &envVol.speedModSrc2, &envVol.speedModAmount2, 2, MouseOverKnob::modAmountConversion::percentage);
    registerSaturnSource(decayTime, speedMod1, &envVol.speedModSrc1, &envVol.speedModAmount1, 1, MouseOverKnob::modAmountConversion::percentage);
    registerSaturnSource(decayTime, speedMod2, &envVol.speedModSrc2, &envVol.speedModAmount2, 2, MouseOverKnob::modAmountConversion::percentage);
    registerSaturnSource(releaseTime, speedMod1, &envVol.speedModSrc1, &envVol.speedModAmount1, 1, MouseOverKnob::modAmountConversion::percentage);
    registerSaturnSource(releaseTime, speedMod2, &envVol.speedModSrc2, &envVol.speedModAmount2, 2, MouseOverKnob::modAmountConversion::percentage);

    registerCombobox(envSpeedModSrc1, &envVol.speedModSrc1, { attackTime, decayTime, releaseTime }, std::bind(&EnvPanel::updateModAmountKnobs, this));
    registerCombobox(envSpeedModSrc2, &envVol.speedModSrc2, { attackTime, decayTime, releaseTime }, std::bind(&EnvPanel::updateModAmountKnobs, this));
    //[/UserPreSize]

    setSize (266, 252);


    //[Constructor] You can add your own custom stuff here..
    speedMod1->setAlwaysOnTop(true);
    speedMod2->setAlwaysOnTop(true);
    //[/Constructor]
}

EnvPanel::~EnvPanel()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    attackTime = nullptr;
    decayTime = nullptr;
    sustainLevel = nullptr;
    releaseTime = nullptr;
    attackShape = nullptr;
    decayShape = nullptr;
    releaseShape = nullptr;
    speedMod1 = nullptr;
    envelopeCurve = nullptr;
    shapeLabel1 = nullptr;
    envSpeedModSrc2 = nullptr;
    envSpeedModSrc1 = nullptr;
    speedMod2 = nullptr;
    speedModLabel = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void EnvPanel::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xffbfa65a));

    //[UserPaint] Add your own custom painting code here..
    drawGroupBorder(g, envVol.name, 0, 0,
                    this->getWidth(), this->getHeight() - 22, 25.0f, 20.0f, 4.0f, 3.0f, 50,SynthParams::envColour);

    int smallBorderHeight = 40;
    drawGroupBorder(g, "", 10, (this->getHeight() - 24) / 2 - (smallBorderHeight - 12) / 2,
        this->getWidth() - 20, smallBorderHeight, 3.0f, 10.0f, 3.0f, 3.0f, 50,SynthParams::envColour);
    // NOTE: debug
    // TODO: panel is cutoff 22 pixel from below
    //g.setColour(Colours::red);
    //g.drawRect(0, 0, 10, 178);
    //g.drawRect(15, 0, 10, 200); // this (or height = 199) should be completely visible
    //g.drawRect(30, 0, 10, 222);
    //[/UserPaint]
}

void EnvPanel::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    int cID = ComboBox::ColourIds::backgroundColourId;
    envSpeedModSrc1->setColour(cID, envSpeedModSrc1->findColour(cID).withAlpha(envVol.speedModSrc1.getStep() == eModSource::eNone ? 0.5f : 1.0f));
    envSpeedModSrc2->setColour(cID, envSpeedModSrc2->findColour(cID).withAlpha(envVol.speedModSrc2.getStep() == eModSource::eNone ? 0.5f : 1.0f));
    //[/UserPreResize]

    attackTime->setBounds (8, 36, 64, 64);
    decayTime->setBounds (69, 36, 64, 64);
    sustainLevel->setBounds (132, 36, 64, 64);
    releaseTime->setBounds (195, 36, 64, 64);
    attackShape->setBounds (30, 110, 20, 20);
    decayShape->setBounds (91, 110, 20, 20);
    releaseShape->setBounds (216, 110, 20, 20);
    speedMod1->setBounds (32, 148, 18, 18);
    envelopeCurve->setBounds (117, 147, 128, 64);
    shapeLabel1->setBounds (134, 107, 60, 24);
    envSpeedModSrc2->setBounds (53, 174, 40, 18);
    envSpeedModSrc1->setBounds (53, 148, 40, 18);
    speedMod2->setBounds (32, 174, 18, 18);
    speedModLabel->setBounds (20, 194, 95, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void EnvPanel::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    handleSlider(sliderThatWasMoved);
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == attackTime)
    {
        //[UserSliderCode_attackTime] -- add your slider handling code here..
        //[/UserSliderCode_attackTime]
    }
    else if (sliderThatWasMoved == decayTime)
    {
        //[UserSliderCode_decayTime] -- add your slider handling code here..
        //[/UserSliderCode_decayTime]
    }
    else if (sliderThatWasMoved == sustainLevel)
    {
        //[UserSliderCode_sustainLevel] -- add your slider handling code here..
        //[/UserSliderCode_sustainLevel]
    }
    else if (sliderThatWasMoved == releaseTime)
    {
        //[UserSliderCode_releaseTime] -- add your slider handling code here..
        //[/UserSliderCode_releaseTime]
    }
    else if (sliderThatWasMoved == attackShape)
    {
        //[UserSliderCode_attackShape] -- add your slider handling code here..
        //[/UserSliderCode_attackShape]
    }
    else if (sliderThatWasMoved == decayShape)
    {
        //[UserSliderCode_decayShape] -- add your slider handling code here..
        //[/UserSliderCode_decayShape]
    }
    else if (sliderThatWasMoved == releaseShape)
    {
        //[UserSliderCode_releaseShape] -- add your slider handling code here..
        //[/UserSliderCode_releaseShape]
    }
    else if (sliderThatWasMoved == speedMod1)
    {
        //[UserSliderCode_speedMod1] -- add your slider handling code here..
        //[/UserSliderCode_speedMod1]
    }
    else if (sliderThatWasMoved == speedMod2)
    {
        //[UserSliderCode_speedMod2] -- add your slider handling code here..
        //[/UserSliderCode_speedMod2]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void EnvPanel::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    handleCombobox(comboBoxThatHasChanged);
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == envSpeedModSrc2)
    {
        //[UserComboBoxCode_envSpeedModSrc2] -- add your combo box handling code here..
        //[/UserComboBoxCode_envSpeedModSrc2]
    }
    else if (comboBoxThatHasChanged == envSpeedModSrc1)
    {
        //[UserComboBoxCode_envSpeedModSrc1] -- add your combo box handling code here..
        //[/UserComboBoxCode_envSpeedModSrc1]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void EnvPanel::updateCurve()
{
    envelopeCurve->setAttack(static_cast<float>(attackTime->getValue()));
    envelopeCurve->setDecay(static_cast<float>(decayTime->getValue()));
    envelopeCurve->setSustain(static_cast<float>(sustainLevel->getValue()));
    envelopeCurve->setRelease(static_cast<float>(releaseTime->getValue()));
    envelopeCurve->setAttackShape(static_cast<float>(attackShape->getValue()));
    envelopeCurve->setDecayShape(static_cast<float>(decayShape->getValue()));
    envelopeCurve->setReleaseShape(static_cast<float>(releaseShape->getValue()));
    repaint();
}

void EnvPanel::updateModAmountKnobs()
{
    speedMod1->setEnabled(envVol.speedModSrc1.getStep() != eModSource::eNone);
    speedMod1->showBipolarValues(isUnipolar(envVol.speedModSrc1.getStep()));
    speedMod2->setEnabled(envVol.speedModSrc2.getStep() != eModSource::eNone);
    speedMod2->showBipolarValues(isUnipolar(envVol.speedModSrc2.getStep()));
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="EnvPanel" componentName=""
                 parentClasses="public PanelBase" constructorParams="SynthParams &amp;p"
                 variableInitialisers="PanelBase(p),&#10;envVol(p.envVol[0])"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="266" initialHeight="252">
  <BACKGROUND backgroundColour="ffbfa65a"/>
  <SLIDER name="Attack Time" id="3c32cde7173ddbe6" memberName="attackTime"
          virtualName="MouseOverKnob" explicitFocusOrder="0" pos="8 36 64 64"
          rotarysliderfill="ffbfa65a" textboxtext="ffffffff" textboxbkgd="ffffff"
          textboxoutline="ffffff" min="0.001" max="5" int="0" style="RotaryVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="56"
          textBoxHeight="20" skewFactor="0.5"/>
  <SLIDER name="Decay Time" id="84a4159bee0728d6" memberName="decayTime"
          virtualName="MouseOverKnob" explicitFocusOrder="0" pos="69 36 64 64"
          rotarysliderfill="ffbfa65a" textboxtext="ffffffff" textboxbkgd="ffffff"
          textboxoutline="ffffff" min="0.001" max="5" int="0" style="RotaryVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="56"
          textBoxHeight="20" skewFactor="0.5"/>
  <SLIDER name="Sustain" id="4bc867c016d7595f" memberName="sustainLevel"
          virtualName="MouseOverKnob" explicitFocusOrder="0" pos="132 36 64 64"
          rotarysliderfill="ffbfa65a" textboxtext="ffffffff" textboxbkgd="ffffff"
          textboxoutline="ffffff" min="-96" max="0" int="0" style="RotaryVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="56"
          textBoxHeight="20" skewFactor="3"/>
  <SLIDER name="Release Time" id="c8bc1120a33101cd" memberName="releaseTime"
          virtualName="MouseOverKnob" explicitFocusOrder="0" pos="195 36 64 64"
          rotarysliderfill="ffbfa65a" textboxtext="ffffffff" textboxbkgd="ffffff"
          textboxoutline="ffffff" min="0.001" max="5" int="0" style="RotaryVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="56"
          textBoxHeight="20" skewFactor="0.5"/>
  <SLIDER name="Attack Shape" id="27ef7f1857e5d79b" memberName="attackShape"
          virtualName="MouseOverKnob" explicitFocusOrder="0" pos="30 110 20 20"
          rotarysliderfill="ffffffff" min="0.01" max="10" int="0" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="0" textBoxHeight="0"
          skewFactor="0.29999999999999999"/>
  <SLIDER name="Decay Shape" id="18adbff3650623b1" memberName="decayShape"
          virtualName="MouseOverKnob" explicitFocusOrder="0" pos="91 110 20 20"
          rotarysliderfill="ffffffff" min="0.01" max="10" int="0" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="0" textBoxHeight="0"
          skewFactor="0.29999999999999999"/>
  <SLIDER name="Release Shape" id="adb5f4f555fb76d1" memberName="releaseShape"
          virtualName="MouseOverKnob" explicitFocusOrder="0" pos="216 110 20 20"
          rotarysliderfill="ffffffff" min="0.01" max="10" int="0" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="0" textBoxHeight="0"
          skewFactor="0.29999999999999999"/>
  <SLIDER name="speedMod1" id="595a20e744f094d5" memberName="speedMod1"
          virtualName="MouseOverKnob" explicitFocusOrder="0" pos="32 148 18 18"
          rotarysliderfill="ffffffff" textboxtext="ffffffff" textboxbkgd="ffffff"
          textboxoutline="ffffff" min="0" max="8" int="0" style="RotaryVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="0" textBoxWidth="0"
          textBoxHeight="0" skewFactor="1"/>
  <GENERICCOMPONENT name="Envelope Curve" id="c0212157938fff27" memberName="envelopeCurve"
                    virtualName="EnvelopeCurve" explicitFocusOrder="0" pos="117 147 128 64"
                    class="Component" params="envVol.attack.get(), envVol.decay.get(), envVol.sustain.get(), envVol.release.get(),  envVol.attackShape.get(), envVol.decayShape.get(), envVol.releaseShape.get()&#10;"/>
  <LABEL name="new label" id="79aa8d544da4882d" memberName="shapeLabel1"
         virtualName="" explicitFocusOrder="0" pos="134 107 60 24" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="shape" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Bauhaus LightA"
         fontsize="20" bold="0" italic="0" justification="36"/>
  <COMBOBOX name="envSpeedModSrcBox2" id="6dae6bde5fbe8153" memberName="envSpeedModSrc2"
            virtualName="ModSourceBox" explicitFocusOrder="0" pos="53 174 40 18"
            editable="0" layout="36" items="" textWhenNonSelected="No Mod"
            textWhenNoItems="(no choices)"/>
  <COMBOBOX name="envSpeedModSrcBox1" id="401dffa72d979c97" memberName="envSpeedModSrc1"
            virtualName="ModSourceBox" explicitFocusOrder="0" pos="53 148 40 18"
            editable="0" layout="36" items="" textWhenNonSelected="No Mod"
            textWhenNoItems="(no choices)"/>
  <SLIDER name="speedMod2" id="b297d9c76ec18bf9" memberName="speedMod2"
          virtualName="MouseOverKnob" explicitFocusOrder="0" pos="32 174 18 18"
          rotarysliderfill="ffffffff" textboxtext="ffffffff" textboxbkgd="ffffff"
          textboxoutline="ffffff" min="0" max="8" int="0" style="RotaryVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="0" textBoxWidth="0"
          textBoxHeight="0" skewFactor="1"/>
  <LABEL name="new label" id="4eec3e2c98c3d079" memberName="speedModLabel"
         virtualName="" explicitFocusOrder="0" pos="20 194 95 24" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="speed mod" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Bauhaus LightA"
         fontsize="20" bold="0" italic="0" justification="36"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
