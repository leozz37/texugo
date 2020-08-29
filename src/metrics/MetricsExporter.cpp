#include "texugo/metrics/MetricsExporter.hpp"
#include <memory>
#include <prometheus/exposer.h>
#include <prometheus/registry.h>
#include "texugo/log/Logger.hpp"

void MetricsExporter::exportRegistry(const std::weak_ptr<prometheus::Registry>& registry) {
    m_exposer ? m_exposer->RegisterCollectable(registry)
              : m_pendingRegistries.push_back(registry);
}

void MetricsExporter::start(const std::string& bindAddress) {
    m_exposer = std::make_unique<prometheus::Exposer>(std::string(bindAddress));

    for (auto& registry : m_pendingRegistries) {
        m_exposer->RegisterCollectable(registry);
    }

    Logger::getInstance().logWarn("METRICS SYSTEM STARTED EXPORTING TO: " + bindAddress);
}

MetricsExporter& MetricsExporter::getInstance() {
    static MetricsExporter instance;
    return instance;
}