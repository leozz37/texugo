#pragma once
#include <memory>
#include <string>
#include <vector>
#include <prometheus/counter.h>
#include <prometheus/exposer.h>
#include <prometheus/registry.h>

class MetricsExporter {
public:
    MetricsExporter(const MetricsExporter& other) noexcept = delete;
    MetricsExporter(MetricsExporter&& other) noexcept = delete;
    MetricsExporter& operator = (const MetricsExporter& other) noexcept = delete;
    MetricsExporter& operator = (MetricsExporter&& other) noexcept = delete;

    void exportRegistry(const std::weak_ptr<prometheus::Registry>&);
    void start(const std::string&);
    static MetricsExporter& getInstance();

private:
    MetricsExporter() noexcept = default;
    std::unique_ptr<prometheus::Exposer> m_exposer;
    std::vector<std::weak_ptr<prometheus::Registry>> m_pendingRegistries;

};