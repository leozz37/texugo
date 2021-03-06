#include <catch2/catch.hpp>
#include "texugo/config/Settings.hpp"

 class SettingsFixture {
 public:
     SettingsFixture() {
         settings = new Settings(configPath);
     }

 protected:
     const std::string configPath = "../../resources/settings.json";
     Settings *settings;
 };

TEST_CASE_METHOD(SettingsFixture, "GetMongoPath") {
    Settings testSettings(configPath);

    const std::string& result = testSettings.getMongoPath();
    const std::string expected = settings->getMongoPath();

    REQUIRE(result == expected);
 }

TEST_CASE_METHOD(SettingsFixture, "GetLogPath") {
    Settings testSettings(configPath);

    const std::string& result = testSettings.getLogPath();
    const std::string expected = settings->getLogPath();

    REQUIRE(result == expected);
 }

TEST_CASE_METHOD(SettingsFixture, "GetMetricsAddress") {
    Settings testSettings(configPath);

    const std::string& result = testSettings.getMetricsAddress();
    const std::string expected = settings->getMetricsAddress();

    REQUIRE(result == expected);
 }

TEST_CASE_METHOD(SettingsFixture, "GetReceiverAddresses") {
    Settings testSettings(configPath);

    const auto& result = testSettings.getReceiverAddresses();
    const auto expected = settings->getReceiverAddresses();

    REQUIRE(result == expected);
 }

TEST_CASE_METHOD(SettingsFixture, "GetSenderAddresses") {
    Settings testSettings(configPath);

    const auto& result = testSettings.getSenderAddresses();
    const auto expected = settings->getSenderAddresses();

    REQUIRE(result == expected);
}