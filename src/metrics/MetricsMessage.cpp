#include "texugo/metrics/MetricsMessage.hpp"
#include "texugo/metrics/MetricsExporter.hpp"

MetricsMessage::MetricsMessage(const std::string& name)
: m_registry(std::make_shared<prometheus::Registry>())
{
    auto& messagesFamily = prometheus::BuildCounter()
            .Name(name+"_messages_total")
            .Help("Total messages on connection: "+name)
            .Register(*m_registry);

    m_counter = &messagesFamily.Add({{name ,"message" }});
    MetricsExporter::getInstance().exportRegistry(m_registry);
}

void MetricsMessage::incrementCounter()
{
    m_counter->Increment();
}