#include "VariableDelay.h"

VariableDelay::VariableDelay (size_t size) :
    l0Delay (size),
    l1Delay (size),
    l3Delay (size),
    l5Delay (size)
{}

void VariableDelay::setDelay (float newDelayInSamples)
{
    delaySmooth.setTargetValue (newDelayInSamples);
}

void VariableDelay::setDelayType (DelayType newType)
{
    auto oldType = type;

    // copy state and parameters first...
    delays[newType]->setDelay (delays[oldType]->getDelay());
    delays[newType]->copyState (*delays[oldType]);

    // then set new type
    type = newType;
}

void VariableDelay::prepare (const juce::dsp::ProcessSpec& spec)
{
    delaySmooth.reset (spec.sampleRate, 0.025);

    for (auto* delay : delays)
        delay->prepare (spec);
}

void VariableDelay::reset()
{
    for (auto* delay : delays)
        delay->reset();
}
