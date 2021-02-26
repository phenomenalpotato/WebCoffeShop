#include "crow.h"

int main(void) {

    crow::SimpleApp app;
    crow::mustache::set_base(".");

    CROW_ROUTE(app, "/") ([]() {

        crow::mustache::context ctx;

        crow::mustache::context css;

        auto main_page = crow::mustache::load("index.html");

        auto style = crow::mustache::load("reset.css");

        return main_page.render();

    });

    app.port(8080).run();
}