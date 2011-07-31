#include "checkbox.h"

//UICheckbox

UICheckbox::UICheckbox(bool* value) : value(value), UIElement() {
    checktex = texturemanager.grab("ui/checkbox.png");
    rect = vec2f(16, 16.0f);
}

void UICheckbox::toggle() {
    *value = !(*value);
}

void UICheckbox::drawContent() {
    checktex->bind();

    //background
    if(*value) {
        drawQuad(vec2f(16.0f,16.0f), vec4f(0.0f, 0.5f, 0.5f, 1.0f));
    } else {
        drawQuad(vec2f(16.0f,16.0f), vec4f(0.0f, 0.0f, 0.5f, 0.5f));
    }
}

//UILabelCheckbox

UILabelCheckbox::UILabelCheckbox(const std::string& label, bool* value) : UILayout(true) {

    addElement(new UILabel(label));
    addElement(new UICheckbox(value));

    padding = 5.0f;
}
