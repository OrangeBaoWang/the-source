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
    : PanelBase(p)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (attackTime = new MouseOverKnob ("Attack Time"));
    attackTime->setRange (0.001, 5, 0);
    attackTime->setSliderStyle (Slider::RotaryVerticalDrag);
    attackTime->setTextBoxStyle (Slider::TextBoxBelow, false, 64, 20);
    attackTime->setColour (Slider::rotarySliderFillColourId, Colour (0xffbfa65a));
    attackTime->setColour (Slider::textBoxTextColourId, Colours::white);
    attackTime->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    attackTime->setColour (Slider::textBoxOutlineColourId, Colour (0x00ffffff));
    attackTime->addListener (this);
    attackTime->setSkewFactor (0.5);

    addAndMakeVisible (decayTime = new MouseOverKnob ("Decay Time"));
    decayTime->setRange (0.001, 5, 0);
    decayTime->setSliderStyle (Slider::RotaryVerticalDrag);
    decayTime->setTextBoxStyle (Slider::TextBoxBelow, false, 64, 20);
    decayTime->setColour (Slider::rotarySliderFillColourId, Colour (0xffbfa65a));
    decayTime->setColour (Slider::textBoxTextColourId, Colours::white);
    decayTime->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    decayTime->setColour (Slider::textBoxOutlineColourId, Colour (0x00ffffff));
    decayTime->addListener (this);
    decayTime->setSkewFactor (0.5);

    addAndMakeVisible (sustainLevel = new MouseOverKnob ("Sustain"));
    sustainLevel->setRange (-96, 0, 0);
    sustainLevel->setSliderStyle (Slider::RotaryVerticalDrag);
    sustainLevel->setTextBoxStyle (Slider::TextBoxBelow, false, 64, 20);
    sustainLevel->setColour (Slider::rotarySliderFillColourId, Colour (0xffbfa65a));
    sustainLevel->setColour (Slider::textBoxTextColourId, Colours::white);
    sustainLevel->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    sustainLevel->setColour (Slider::textBoxOutlineColourId, Colour (0x00ffffff));
    sustainLevel->addListener (this);
    sustainLevel->setSkewFactor (3);

    addAndMakeVisible (releaseTime = new MouseOverKnob ("Release Time"));
    releaseTime->setRange (0.001, 5, 0);
    releaseTime->setSliderStyle (Slider::RotaryVerticalDrag);
    releaseTime->setTextBoxStyle (Slider::TextBoxBelow, false, 64, 20);
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
    attackShape->setColour (Slider::rotarySliderFillColourId, Colour (0xffbfa65a));
    attackShape->addListener (this);
    attackShape->setSkewFactor (0.3);

    addAndMakeVisible (decayShape = new MouseOverKnob ("Decay Shape"));
    decayShape->setRange (0.01, 10, 0);
    decayShape->setSliderStyle (Slider::RotaryVerticalDrag);
    decayShape->setTextBoxStyle (Slider::NoTextBox, false, 0, 0);
    decayShape->setColour (Slider::rotarySliderFillColourId, Colour (0xffbfa65a));
    decayShape->addListener (this);
    decayShape->setSkewFactor (0.3);

    addAndMakeVisible (releaseShape = new MouseOverKnob ("Release Shape"));
    releaseShape->setRange (0.01, 10, 0);
    releaseShape->setSliderStyle (Slider::RotaryVerticalDrag);
    releaseShape->setTextBoxStyle (Slider::NoTextBox, false, 0, 0);
    releaseShape->setColour (Slider::rotarySliderFillColourId, Colour (0xffbfa65a));
    releaseShape->addListener (this);
    releaseShape->setSkewFactor (0.3);

    addAndMakeVisible (keyVelToEnv = new MouseOverKnob ("Vel to Env"));
    keyVelToEnv->setRange (0, 1, 0);
    keyVelToEnv->setSliderStyle (Slider::RotaryVerticalDrag);
    keyVelToEnv->setTextBoxStyle (Slider::TextBoxBelow, true, 64, 20);
    keyVelToEnv->setColour (Slider::rotarySliderFillColourId, Colour (0xffbfa65a));
    keyVelToEnv->setColour (Slider::textBoxTextColourId, Colours::white);
    keyVelToEnv->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    keyVelToEnv->setColour (Slider::textBoxOutlineColourId, Colour (0x00ffffff));
    keyVelToEnv->addListener (this);

    addAndMakeVisible (envelopeCurve = new EnvelopeCurve (params.envAttack.get(), params.envDecay.get(), params.envSustain.get(), params.envRelease.get(),  params.envAttackShape.get(), params.envDecayShape.get(), params.envReleaseShape.get()
                                                          ));
    envelopeCurve->setName ("Envelope Curve");

    addAndMakeVisible (label = new Label ("new label",
                                          TRANS("shape")));
    label->setFont (Font ("Bauhaus 93", 20.00f, Font::plain));
    label->setJustificationType (Justification::centred);
    label->setEditable (false, false, false);
    label->setColour (Label::textColourId, Colours::white);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]
    registerSlider(attackTime, &params.envAttack);
    registerSlider(decayTime, &params.envDecay);
    registerSlider(sustainLevel, &params.envSustain);
    registerSlider(releaseTime, &params.envRelease);
    registerSlider(attackShape, &params.envAttackShape);
    registerSlider(decayShape, &params.envDecayShape);
    registerSlider(releaseShape, &params.envReleaseShape);
    registerSlider(keyVelToEnv, &params.keyVelToEnv);
    //[/UserPreSize]

    setSize (800, 252);


    //[Constructor] You can add your own custom stuff here..
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
    keyVelToEnv = nullptr;
    envelopeCurve = nullptr;
    label = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void EnvPanel::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xffcbca63));

    //[UserPaint] Add your own custom painting code here..
    drawGroupBorder(g, "vol env", 0, 0,
        this->getWidth() / 3, this->getHeight(), 25.0f, 20.0f, 5.0f, 3.0f, Colour(0xffcbca63));
    drawGroupBorder(g, "env 1", this->getWidth() / 3, 0,
        this->getWidth() / 3, this->getHeight(), 25.0f, 20.0f, 5.0f, 3.0f, Colour(0xffcbca63));
    drawGroupBorder(g, "env 2", this->getWidth() / 3 * 2, 0,
        this->getWidth() / 3, this->getHeight(), 25.0f, 20.0f, 5.0f, 3.0f, Colour(0xffcbca63));
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
    //[/UserPreResize]

    attackTime->setBounds (8, 32, 64, 64);
    decayTime->setBounds (60, 32, 64, 64);
    sustainLevel->setBounds (112, 32, 64, 64);
    releaseTime->setBounds (164, 32, 64, 64);
    attackShape->setBounds (29, 108, 20, 20);
    decayShape->setBounds (80, 108, 20, 20);
    releaseShape->setBounds (185, 108, 20, 20);
    keyVelToEnv->setBounds (8, 142, 64, 64);
    envelopeCurve->setBounds (95, 142, 128, 64);
    label->setBounds (101, 106, 96, 24);
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
        envelopeCurve->setAttack(static_cast<float>(attackTime->getValue()));
        envelopeCurve->repaint();
        //[/UserSliderCode_attackTime]
    }
    else if (sliderThatWasMoved == decayTime)
    {
        //[UserSliderCode_decayTime] -- add your slider handling code here..
        envelopeCurve->setDecay(static_cast<float>(decayTime->getValue()));
        envelopeCurve->repaint();
        //[/UserSliderCode_decayTime]
    }
    else if (sliderThatWasMoved == sustainLevel)
    {
        //[UserSliderCode_sustainLevel] -- add your slider handling code here..
        envelopeCurve->setSustain(static_cast<float>(sustainLevel->getValue()));
        envelopeCurve->repaint();
        //[/UserSliderCode_sustainLevel]
    }
    else if (sliderThatWasMoved == releaseTime)
    {
        //[UserSliderCode_releaseTime] -- add your slider handling code here..
        envelopeCurve->setRelease(static_cast<float>(releaseTime->getValue()));
        envelopeCurve->repaint();
        //[/UserSliderCode_releaseTime]
    }
    else if (sliderThatWasMoved == attackShape)
    {
        //[UserSliderCode_attackShape] -- add your slider handling code here..
        envelopeCurve->setAttackShape(static_cast<float>(attackShape->getValue()));
        envelopeCurve->repaint();
        //[/UserSliderCode_attackShape]
    }
    else if (sliderThatWasMoved == decayShape)
    {
        //[UserSliderCode_decayShape] -- add your slider handling code here..
        envelopeCurve->setDecayShape(static_cast<float>(decayShape->getValue()));
        envelopeCurve->repaint();
        //[/UserSliderCode_decayShape]
    }
    else if (sliderThatWasMoved == releaseShape)
    {
        //[UserSliderCode_releaseShape] -- add your slider handling code here..
        envelopeCurve->setReleaseShape(static_cast<float>(releaseShape->getValue()));
        envelopeCurve->repaint();
        //[/UserSliderCode_releaseShape]
    }
    else if (sliderThatWasMoved == keyVelToEnv)
    {
        //[UserSliderCode_keyVelToEnv] -- add your slider handling code here..
        //[/UserSliderCode_keyVelToEnv]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="EnvPanel" componentName=""
                 parentClasses="public PanelBase" constructorParams="SynthParams &amp;p"
                 variableInitialisers="PanelBase(p)" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="0" initialWidth="800"
                 initialHeight="252">
  <BACKGROUND backgroundColour="ffcbca63"/>
  <SLIDER name="Attack Time" id="3c32cde7173ddbe6" memberName="attackTime"
          virtualName="MouseOverKnob" explicitFocusOrder="0" pos="8 32 64 64"
          rotarysliderfill="ffbfa65a" textboxtext="ffffffff" textboxbkgd="ffffff"
          textboxoutline="ffffff" min="0.001" max="5" int="0" style="RotaryVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="64"
          textBoxHeight="20" skewFactor="0.5"/>
  <SLIDER name="Decay Time" id="84a4159bee0728d6" memberName="decayTime"
          virtualName="MouseOverKnob" explicitFocusOrder="0" pos="60 32 64 64"
          rotarysliderfill="ffbfa65a" textboxtext="ffffffff" textboxbkgd="ffffff"
          textboxoutline="ffffff" min="0.001" max="5" int="0" style="RotaryVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="64"
          textBoxHeight="20" skewFactor="0.5"/>
  <SLIDER name="Sustain" id="4bc867c016d7595f" memberName="sustainLevel"
          virtualName="MouseOverKnob" explicitFocusOrder="0" pos="112 32 64 64"
          rotarysliderfill="ffbfa65a" textboxtext="ffffffff" textboxbkgd="ffffff"
          textboxoutline="ffffff" min="-96" max="0" int="0" style="RotaryVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="64"
          textBoxHeight="20" skewFactor="3"/>
  <SLIDER name="Release Time" id="c8bc1120a33101cd" memberName="releaseTime"
          virtualName="MouseOverKnob" explicitFocusOrder="0" pos="164 32 64 64"
          rotarysliderfill="ffbfa65a" textboxtext="ffffffff" textboxbkgd="ffffff"
          textboxoutline="ffffff" min="0.001" max="5" int="0" style="RotaryVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="64"
          textBoxHeight="20" skewFactor="0.5"/>
  <SLIDER name="Attack Shape" id="27ef7f1857e5d79b" memberName="attackShape"
          virtualName="MouseOverKnob" explicitFocusOrder="0" pos="29 108 20 20"
          rotarysliderfill="ffbfa65a" min="0.01" max="10" int="0" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="0" textBoxHeight="0"
          skewFactor="0.29999999999999999"/>
  <SLIDER name="Decay Shape" id="18adbff3650623b1" memberName="decayShape"
          virtualName="MouseOverKnob" explicitFocusOrder="0" pos="80 108 20 20"
          rotarysliderfill="ffbfa65a" min="0.01" max="10" int="0" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="0" textBoxHeight="0"
          skewFactor="0.29999999999999999"/>
  <SLIDER name="Release Shape" id="adb5f4f555fb76d1" memberName="releaseShape"
          virtualName="MouseOverKnob" explicitFocusOrder="0" pos="185 108 20 20"
          rotarysliderfill="ffbfa65a" min="0.01" max="10" int="0" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="0" textBoxHeight="0"
          skewFactor="0.29999999999999999"/>
  <SLIDER name="Vel to Env" id="595a20e744f094d5" memberName="keyVelToEnv"
          virtualName="MouseOverKnob" explicitFocusOrder="0" pos="8 142 64 64"
          rotarysliderfill="ffbfa65a" textboxtext="ffffffff" textboxbkgd="ffffff"
          textboxoutline="ffffff" min="0" max="1" int="0" style="RotaryVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="0" textBoxWidth="64"
          textBoxHeight="20" skewFactor="1"/>
  <GENERICCOMPONENT name="Envelope Curve" id="c0212157938fff27" memberName="envelopeCurve"
                    virtualName="EnvelopeCurve" explicitFocusOrder="0" pos="95 142 128 64"
                    class="Component" params="params.envAttack.get(), params.envDecay.get(), params.envSustain.get(), params.envRelease.get(),  params.envAttackShape.get(), params.envDecayShape.get(), params.envReleaseShape.get()&#10;"/>
  <LABEL name="new label" id="79aa8d544da4882d" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="101 106 96 24" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="shape" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Bauhaus 93"
         fontsize="20" bold="0" italic="0" justification="36"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
