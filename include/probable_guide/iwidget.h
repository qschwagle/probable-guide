#pragma once

#include <memory>
#include <string>
#include <vector>

#include <probable_guide/point.h>
#include <probable_guide/rect.h>

namespace probable_guide
{
class IWidget
{
public:
    /**
     * focusable
     */
    virtual std::shared_ptr<IWidget> FocusHit(const Point pt)=0;

    /**
     * Clickable
     */
    virtual std::shared_ptr<IWidget> ClickHit(const Point pt)=0;

    /**
     * Double Clickable
     */
    virtual std::shared_ptr<IWidget> DoubleClickHit(const Point pt)=0;

    /**
     * Renderable
     */
    virtual void Render()=0;

    /**
     * Sizable
     */
    virtual Rect GetDimensions()=0;

    /**
     * Positionable
     */
    virtual Point GetPosition()=0;

    /**
     * Disable
     */
    virtual bool IsDisabled()=0;

    /**
     * Disable
     */
    virtual void SetDisabled(bool state)=0;

    /**
     * draggable
     */
    virtual std::shared_ptr<IWidget> Dragable()=0;

    /**
     * Draggable
     */
    virtual std::vector<std::string> GetDragTargets()=0;

    /**
     * Dropzone
     */
    virtual std::shared_ptr<IWidget> DropzoneHit(Point pt)=0;

    /** 
     * Dropzone 
     * */
    virtual bool DropzoneAccept(std::shared_ptr<IWidget> widget)=0;

    /**
     * Dropzone
     */
    virtual std::string DropZoneType()=0;

};
}
