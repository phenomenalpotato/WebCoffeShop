#include "crow.h"

int main(void) {

    crow::SimpleApp app;
    crow::mustache::set_base(".");

    CROW_ROUTE(app, "/") ([]() {

        crow::mustache::context ctx;

        // crow::mustache::context css;

        auto main_page = crow::mustache::load("static/index.html");

        auto style = crow::mustache::default_loader("static/index.html");

        return main_page.render();

    });

        CROW_ROUTE(app, "/reset.css") ([]() {

        crow::mustache::context css;

        auto style = crow::mustache::load("static/reset.css");

        return style.render();

    });

    app.port(8080).run();
}