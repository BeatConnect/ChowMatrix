#pragma once

#include "dsp/Parameters/HostParamControl.h"

class HostControlMenuComp : public PopupMenu::CustomComponent
{
public:
    HostControlMenuComp (HostParamControl& controller, size_t idx);
    static void createXButton (DrawableButton& xButton);

    void getIdealSize (int& idealWidth, int& idealHeight) override;
    void paint (Graphics& g) override;
    void resized() override;

private:
    String name;
    StringArray paramList;

    OwnedArray<DrawableButton> xButtons;
    std::vector<std::function<void()>> xCallbacks;

    static constexpr float font = 16.0f;
    static constexpr int labelHeight = 25;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (HostControlMenuComp)
};
