//
//  VROInputControllerOVR.h
//  ViroRenderer
//
//  Copyright © 2017 Viro Media. All rights reserved.
//

#ifndef VROInputControllerOVR_H
#define VROInputControllerOVR_H
#include <memory>
#include "VRORenderContext.h"
#include "VROInputControllerBase.h"
#include "VROInputPresenterOVR.h"
#include <android/input.h>

class VROInputControllerOVR : public VROInputControllerBase {

public:
    VROInputControllerOVR(){}
    virtual ~VROInputControllerOVR(){}

    void onProcess();
    void handleOVRKeyEvent(int keyCode, int action);
    void handleOVRTouchEvent(int touchAction, float posX, float posY);
    void updateSwipeGesture(VROVector3f start, VROVector3f end);
protected:
    std::shared_ptr<VROInputPresenter> createPresenter(std::shared_ptr<VRORenderContext> context){
        return std::make_shared<VROInputPresenterOVR>(context);
    }

private:
    VROVector3f _touchDownLocationStart;
};
#endif