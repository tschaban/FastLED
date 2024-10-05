#pragma once

#include <stdint.h>
#include "namespace.h"
#include "crgb.h"
#include "util/transition.h"
#include "util/draw_context.h"

FASTLED_NAMESPACE_BEGIN


union FxCapabilities {
    struct {
        uint32_t alphaChannel : 1;
        uint32_t reserved : 31;  // Reserved for future use
    };
    uint32_t value = 0;  // Allow access to the entire 32-bit value

    bool hasAlphaChannel() const { return alphaChannel; }
};

// Abstract base class for effects on a strip/grid of LEDs.
class Fx {
  public:
    typedef DrawContext DrawContext;
    typedef FxCapabilities Capabilities;
    Fx(uint16_t numLeds): mNumLeds(numLeds) {}

    /// @param now The current time in milliseconds. Fx writers are encouraged to use this instead of millis() directly
    /// as this will more deterministic behavior.
    virtual void draw(DrawContext context) = 0;
    virtual Capabilities getCapabilities() const { return Capabilities(); }

    virtual const char* fxName() const = 0;  // Get the name of the current fx. This is the class name if there is only one.
    // Optionally implement these for multi fx classes.
    virtual int fxNum() const { return 1; };  // Return 1 if you only have one fx managed by this class.
    virtual void fxSet(int fx) {};  // Set the current fx number.
    virtual void fxNext(int fx = 1) {};  // Negative numbers are allowed. -1 means previous fx.
    virtual int fxGet() const { return 0; };  // Get the current fx number.

    virtual void pause() {}  // Called when the fx is paused, usually when a transition has finished.
    virtual void resume() {}  // Called when the fx is resumed after a pause, usually when a transition has started.

    virtual ~Fx() {}
    virtual void lazyInit() {}
    uint16_t getNumLeds() const { return mNumLeds; }

protected:
    uint16_t mNumLeds;
};

FASTLED_NAMESPACE_END

