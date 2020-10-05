#pragma once
#include <prometheus/counter.h>
#include <prometheus/exposer.h>
#include <prometheus/registry.h>

class MetricsMessage
{
public:
    MetricsMessage(const std::string&);
    void incrementCounter();

private:
    std::shared_ptr<prometheus::Registry> m_registry;
    prometheus::Counter * m_counter;
};