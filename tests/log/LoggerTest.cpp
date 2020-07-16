#include <gtest/gtest.h>
#include "texugo/log/Logger.hpp"

class SettingsFixture: public testing::Test {
public:
    void SetUp() override;

protected:
    const std::string logPath = "../../log/log_unit_test.txt";
};

void SettingsFixture::SetUp() {
    Logger::getInstance().openLogFile(logPath);
}
