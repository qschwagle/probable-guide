#pragma once

#include <memory>

namespace probable_guide
{

class VulkanContextPrivate;

class VulkanContext : public std::enable_shared_from_this<VulkanContext>
{
private:
    struct Private{};
public:
    VulkanContext(Private) {}
    virtual ~VulkanContext() {}

    bool Init();

    VulkanContext(const VulkanContext&)=delete;
    VulkanContext(const VulkanContext&&)=delete;

    VulkanContext& operator=(const VulkanContext&)=delete;
    VulkanContext& operator=(const VulkanContext&&)=delete;

    static std::shared_ptr<VulkanContext> Create() {
        return std::make_shared<VulkanContext>(Private());
    }

    std::shared_ptr<VulkanContext> GetPtr() {
        return shared_from_this();
    }
private:
    std::shared_ptr<VulkanContextPrivate> mPrivate{nullptr};
};

}
