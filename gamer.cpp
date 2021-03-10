#include "crow_all.h"
#include "s3-upload.cpp"
#include <iostream>

using namespace std;

int send_to_s3(string file_name,string file_data) {

    //If no data to upload, fail immediately
    if (file_name == "" || file_data == ""){
        return 1;
    }

    cout << "Saving: " << file_name;
    std::ofstream out(file_name);
    out << file_data;
    out.close();

    Aws::SDKOptions options;
    Aws::InitAPI(options);
    {

        Aws::String aws_s(file_name.c_str(), file_name.size());
        const Aws::String bucket_name = std::getenv("BUCKET_NAME");
        const Aws::String object_name = aws_s;
        const Aws::String region = std::getenv("BUCKET_REGION");
        if (!AwsDoc::S3::PutObject(bucket_name, object_name, region)) {
            return 1;
        }
    }
    
    Aws::ShutdownAPI(options);

    return 0;
}

int main(void) {

    crow::SimpleApp app;
    crow::mustache::set_base(".");
    app.loglevel(crow::LogLevel::WARNING);
    CROW_ROUTE(app, "/") ([]() {

        crow::mustache::context ctx;

        auto main_page = crow::mustache::load("index.html");

        return main_page.render();

    });

    CROW_ROUTE(app, "/contato.html") ([] () {

        crow::mustache::context ctx2;

        auto contato = crow::mustache::load("/contato.html");

        return contato.render();

    });

    CROW_ROUTE(app, "/index.html") ([] () {

        crow::mustache::context ctx3;

        auto index = crow::mustache::load("/index.html");

        return index.render();

    });

    CROW_ROUTE(app, "/send").methods("POST"_method) ([](const crow::request& req, crow::response& res) {

        //  simply by reading a crow::request
        // crow::multipart::message

        //  Once a multipart message has been made, the individual parts can be accessed throught mpmes.parts, parts is an std::vector, so accessing the individual parts should be straightforward.
        //  In order to access the individual part's name or filename, something like mpmes.parts[0].headers[0].params["name"] sould do the trick.

        auto msg = crow::multipart::message(req);

        // Parts index is defined by the HTML form.
        int result = send_to_s3(msg.parts[5].headers[0].params["filename"],msg.parts[5].body);

        res.redirect("/sent/"+to_string(result));
        res.end();
        
    });

    CROW_ROUTE(app, "/sent/<int>")([](int result) {
        auto submission = crow::mustache::load("/submission.html");
        crow::mustache::context ctx;
        if (result==0){
            ctx["submission_result"]="Recebemos a aplicação com sucesso";
        }
        else{
            ctx["submission_result"]="Infelizmente algo deu errado ):";
        }
        return submission.render(ctx);
    });

    CROW_ROUTE(app, "/css/cafeteria.css") ([]() {

        crow::mustache::context css;

        auto style = crow::mustache::load("/css/cafeteria.css");

        return style.render();

    });

    CROW_ROUTE(app, "/css/font-awesome.min.css") ([] () {

        crow::mustache::context css2;

        auto style2 = crow::mustache::load("/css/font-awesome.min.css");

        return style2.render();

    });

    CROW_ROUTE(app, "/css/materialize.min.css") ([] () {

        crow::mustache::context css3;

        auto style3 = crow::mustache::load("/css/materialize.min.css");

        return style3.render();

    });

    // Routes using args are failing.
    // CROW_ROUTE(app, "/css/<string>") 
    // ([] (string p) {
    //     crow::mustache::context css3;
    //     auto css = crow::mustache::load("/css/"+p);
    //     return css.render();

    // });


    // CROW_ROUTE(app, "/js/<string>") 
    // ([] (string p) {
    //     crow::mustache::context js;
    //     auto script = crow::mustache::load("/js/"+p);
    //     return script.render();

    // });

    // CROW_ROUTE(app, "/imagens/<string>") 
    // ([] (string p) {
    //     crow::mustache::context img;
    //     auto image = crow::mustache::load("/imagens/"+p);
    //     return image.render();
    // });

    // CROW_ROUTE(app, "/fonts/<string>") 
    // ([] (string p) {
    //     crow::mustache::context fon;
    //     auto fonte1 = crow::mustache::load("/fonts/"+p);
    //     return fonte1.render();

    // });    

    CROW_ROUTE(app, "/js/materialize.min.js") ([] () {

        crow::mustache::context js;

        auto style4 = crow::mustache::load("/js/materialize.min.js");

        return style4.render();

    });

    CROW_ROUTE(app, "/js/jquery.js") ([] () {

        crow::mustache::context js2;

        auto style5 = crow::mustache::load("/js/jquery.js");

        return style5.render();

    });

    CROW_ROUTE(app, "/imagens/cafeteria2.png") ([] () {

        crow::mustache::context img;

        auto img1 = crow::mustache::default_loader("/imagens/cafeteria2.png");

        return img1;

    });

    CROW_ROUTE(app, "/imagens/cafe2.jpg") ([] () {

        crow::mustache::context img2;

        auto img3 = crow::mustache::default_loader("/imagens/cafe2.jpg");

        return img3;

    });

    CROW_ROUTE(app, "/imagens/lanche13.jpg") ([] () {

        crow::mustache::context img4;

        auto img5 = crow::mustache::default_loader("/imagens/lanche13.jpg");

        return img5;

    });

    CROW_ROUTE(app, "/imagens/pao4.jpg") ([] () {

        crow::mustache::context img6;

        auto img7 = crow::mustache::default_loader("/imagens/pao4.jpg");

        return img7;

    });

    CROW_ROUTE(app, "/imagens/cafe3.jpg") ([] () {

        crow::mustache::context img8;

        auto img9 = crow::mustache::default_loader("/imagens/cafe3.jpg");

        return img9;

    });

    CROW_ROUTE(app, "/imagens/cafe5.jpg") ([] () {

        crow::mustache::context img10;

        auto img11 = crow::mustache::default_loader("/imagens/cafe5.jpg");

        return img11;

    });

    CROW_ROUTE(app, "/imagens/cafe14.jpg") ([] () {

        crow::mustache::context img12;

        auto img13 = crow::mustache::default_loader("/imagens/cafe14.jpg");

        return img13;

    });

    CROW_ROUTE(app, "/imagens/cafeteria1.jpg") ([] () {

        crow::mustache::context img14;

        auto img15 = crow::mustache::default_loader("/imagens/cafeteria1.jpg");

        return img15;

    });

    CROW_ROUTE(app, "/fonts/roboto/Roboto-Regular.woff2") ([] () {

        crow::mustache::context fon;

        auto fonte1 = crow::mustache::load("/fonts/roboto/Roboto-Regular.woff2");

        return fonte1.render();

    });

    CROW_ROUTE(app, "/fonts/fontawesome-webfont.woff2") ([] () {

        crow::mustache::context fon2;

        auto fonte2 = crow::mustache::load("/fonts/fontawesome-webfont.woff2");

        return fonte2.render();

    });

    CROW_ROUTE(app, "/fonts/roboto/Roboto-Medium.woff2") ([] () {

        crow::mustache::context fon3;

        auto fonte3 = crow::mustache::load("/fonts/roboto/Roboto-Medium.woff2");

        return fonte3.render();

    });

    CROW_ROUTE(app, "/fonts/roboto/Roboto-Regular.woff") ([] () {

        crow::mustache::context fon4;

        auto fonte4 = crow::mustache::load("/fonts/roboto/Roboto-Regular.woff");

        return fonte4.render();

    });

    CROW_ROUTE(app, "/fonts/fontawesome-webfont.woff") ([] () {

        crow::mustache::context fon5;

        auto fonte5 = crow::mustache::load_text("/fonts/fontawesome-webfont.woff");

        return fonte5;

    });

    CROW_ROUTE(app, "/fonts/fontawesome-webfont.ttf") ([] () {

        crow::mustache::context fon6;

        auto fonte6 = crow::mustache::load("/fonts/fontawesome-webfont.ttf");

        return fonte6.render();

    });

    app.port(8080).run();
}
