#include "crow.h"

int main(void) {

    crow::SimpleApp app;

    CROW_ROUTE(app, "/")
    ([]() {
        return "Hello my fellow GaMeR";
    });

    app.port(8080).run();
}