#ifndef UI_SLIDER_H
#define UI_SLIDER_H

#include "element.h"
#include "label.h"
#include "layout.h"

class UISlider : public UIElement {
protected:
    TextureResource* slidertex;
    float slider_width;
    bool background;

    void drawSlider(float position);
public:
    UISlider(const std::string& slider_texure, float width);

    int getType() { return UI_SLIDER; };

    virtual void selectValueAt(const vec2f& pos) {};
};

class UIFloatSlider : public UISlider {
public:
    float* value;
    float min;
    float max;

    UIFloatSlider(float* value, float min, float max);

    void mouseWheel(bool up);
    void selectValueAt(const vec2f& pos);

    void drawContent();
};

class UIIntSlider : public UISlider {
public:
    int* value;
    int min;
    int max;

    UIIntSlider(int* value, int min, int max);

    void mouseWheel(bool up);
    void selectValueAt(const vec2f& pos);

    void drawContent();
};

class UILabelFloatSlider : public UILayout {

public:
    UILabelFloatSlider(const std::string& label, float* value, float min, float max);
};

class UILabelIntSlider : public UILayout {

public:
    UILabelIntSlider(const std::string& label, int* value, int min, int max);
};

#endif
