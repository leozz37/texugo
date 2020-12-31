#include <catch2/catch.hpp>
#include "../../../src/config/Settings.hpp"

class SettingsFixture
{
public:
    SettingsFixture() { settings = new Settings(configPath); }

protected:
    const std::string resourcePath = TEXUGO_TEST_RES_PATH;
    const std::string configPath = resourcePath + "/fixture_settings.json";
    Settings*         settings;
};

TEST_CASE_METHOD(SettingsFixture, "GetMongoPath")
{
    const std::string& result   = settings->getMongoPath();
    const std::string  expected = "127.0.0.1:27017";

    REQUIRE(result == expected);
}

TEST_CASE_METHOD(SettingsFixture, "GetLogPath")
{
    Settings testSettings(configPath);

    const std::string& result   = testSettings.getLogPath();
    const std::string  expected = settings->getLogPath();

    REQUIRE(result == expected);
}

TEST_CASE_METHOD(SettingsFixture, "GetMetricsAddress")
{
    Settings testSettings(configPath);

    const std::string& result   = testSettings.getMetricsAddress();
    const std::string  expected = settings->getMetricsAddress();

    REQUIRE(result == expected);
}

TEST_CASE_METHOD(SettingsFixture, "GetReceiverAddresses")
{
    Settings testSettings(configPath);

    const auto& result   = testSettings.getReceiverAddresses();
    const auto  expected = settings->getReceiverAddresses();

    REQUIRE(result == expected);
}

TEST_CASE_METHOD(SettingsFixture, "GetSenderAddresses")
{
    Settings testSettings(configPath);

    const auto& result   = testSettings.getSenderAddresses();
    const auto  expected = settings->getSenderAddresses();

    REQUIRE(result == expected);
}