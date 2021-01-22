#include "MetricsExporter.hpp"

void MetricsExporter::start(const std::string& bindAddress)
{
    m_exposer = std::make_unique<prometheus::Exposer>(bindAddress);
}

void MetricsExporter::exportRegistry(const std::weak_ptr<prometheus::Registry>& registry)
{
    m_exposer->RegisterCollectable(registry);
}

MetricsExporter& MetricsExporter::getInstance()
{
    static MetricsExporter instance;
    return instance;
}