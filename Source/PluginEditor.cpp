#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
GainAudioProcessorEditor::GainAudioProcessorEditor (GainAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    setSize (200, 400);
    
    sliderAttach = new AudioProcessorValueTreeState::SliderAttachment (processor.treeState, GAIN_ID, gainSlider);
    
    gainSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    gainSlider.setTextBoxStyle(Slider::TextBoxBelow, true, 100, 25);
    gainSlider.setRange(-70.0, 12.0);
    gainSlider.setValue(0.0);
    gainSlider.addListener(this);
    
    addAndMakeVisible(gainSlider);
}

GainAudioProcessorEditor::~GainAudioProcessorEditor()
{
}

//==============================================================================
void GainAudioProcessorEditor::paint (Graphics& g)
{
    
}

void GainAudioProcessorEditor::resized()
{
    gainSlider.setBounds(getLocalBounds());
}

void GainAudioProcessorEditor::sliderValueChanged(Slider *slider)
{
    if(slider == &gainSlider)
    {
        processor.adjustedGain = pow( 10, (gainSlider.getValue() / 20) );
    }
}
