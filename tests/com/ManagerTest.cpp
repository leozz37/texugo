//#include "texugo/com/ConnectionManager.hpp"
//#include <catch2/catch.hpp>
//#include <boost/asio.hpp>
//
//class ManagerFixture {
//public:
//    ManagerFixture() {
//        std::unordered_map<std::string, std::string> routingAddresses;
//        const std::string port = "5555";
//        for (int i = 0; i < 5; i++) {
//            const std::string name = std::to_string(i);
//            routingAddresses.insert({ name, port });
//        }
//        manager = new ConnectionManager(routingAddresses);
//    }
//
//protected:
//    ConnectionManager *manager;
//};
//
////TEST_CASE_METHOD(ManagerFixture, "CreateConnectionNameAlreadyExists") {
////    const std::string name = "AAAAAAA";
////    short port = 5555;
////
////    manager->createConnection(name, port);
////
////    REQUIRE_THROWS(manager->createConnection(name, port));
////}