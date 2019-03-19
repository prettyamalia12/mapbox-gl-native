#include <mbgl/storage/resource_options.hpp>
#include <mbgl/util/constants.hpp>

namespace mbgl {

class ResourceOptions::Impl {
public:
    std::string accessToken;
    std::string baseURL = mbgl::util::API_BASE_URL;
    ResourceTransformFn resourceTransformFn;
    std::string cachePath = ":memory:";
    std::string assetPath = ".";
    uint64_t maximumSize = mbgl::util::DEFAULT_MAX_CACHE_SIZE;
    void* platformContext = nullptr;
};

ResourceOptions::ResourceOptions() : impl_(std::make_shared<ResourceOptions::Impl>()) {}
ResourceOptions::~ResourceOptions() = default;

ResourceOptions& ResourceOptions::withAccessToken(std::string token) {
    impl_->accessToken = std::move(token);
    return *this;
}

const std::string& ResourceOptions::accessToken() const {
    return impl_->accessToken;
}

ResourceOptions& ResourceOptions::withBaseURL(std::string url) {
    impl_->baseURL = std::move(url);
    return *this;
}

const std::string& ResourceOptions::baseURL() const {
    return impl_->baseURL;
}

ResourceOptions& ResourceOptions::withResourceTransform(ResourceTransformFn function) {
    impl_->resourceTransformFn = std::move(function);
    return *this;
}

ResourceTransformFn ResourceOptions::resourceTransform() const {
    return impl_->resourceTransformFn;
}

ResourceOptions& ResourceOptions::withCachePath(std::string path) {
    impl_->cachePath = std::move(path);
    return *this;
}

const std::string& ResourceOptions::cachePath() const {
    return impl_->cachePath;
}

ResourceOptions& ResourceOptions::withAssetPath(std::string path) {
    impl_->assetPath = std::move(path);
    return *this;
}

const std::string& ResourceOptions::assetPath() const {
    return impl_->assetPath;
}

ResourceOptions& ResourceOptions::withMaximumCacheSize(uint64_t size) {
    impl_->maximumSize = size;
    return *this;
}

uint64_t ResourceOptions::maximumCacheSize() const {
    return impl_->maximumSize;
}

ResourceOptions& ResourceOptions::withPlatformContext(void* context) {
    impl_->platformContext = context;
    return *this;
}

void* ResourceOptions::platformContext() const {
    return impl_->platformContext;
}

}  // namespace mbgl
