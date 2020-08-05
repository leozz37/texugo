// #include <gtest/gtest.h>
// #include "texugo/config/Settings.hpp"

// class SettingsFixture: public testing::Test {
// public:
//     void SetUp() override;

// protected:
//     const std::string configPath = "../../resources/settings.json";
//     Settings *settings;
// };

// void SettingsFixture::SetUp() {
//     settings = new Settings(configPath);
// }

// TEST_F(SettingsFixture, GetMongoPath) {
//     Settings testSettings(configPath);

//     const std::string result = testSettings.getMongoPath();
//     const std::string expected = settings->getMongoPath();

//     ASSERT_EQ(result, expected);
// }

// TEST_F(SettingsFixture, GetLogPath) {
//     Settings testSettings(configPath);

//     const std::string result = testSettings.getLogPath();
//     const std::string expected = settings->getLogPath();

//     ASSERT_EQ(result, expected);
// }

// TEST_F(SettingsFixture, GetMetricsAddress) {
//     Settings testSettings(configPath);

//     const std::string result = testSettings.getMetricsAddress();
//     const std::string expected = settings->getMetricsAddress();

//     ASSERT_EQ(result, expected);
// }

// TEST_F(SettingsFixture, GetRoutingAddresses) {
//     Settings testSettings(configPath);

//     const auto result = testSettings.getRoutingAddresses();
//     const auto expected = settings->getRoutingAddresses();

//     ASSERT_EQ(result, expected);
// }

