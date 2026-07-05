#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

// очистка входного буфера
void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void generateFiles(int choice) {
    string fontFamily;
    string fontDescription;

    switch(choice) {
        case 1:
            fontFamily = "SynergySans, sans-serif";
            fontDescription = "SynergySans";
            break;
        case 2:
            fontFamily = "Calibri, sans-serif";
            fontDescription = "Calibri";
            break;
        case 3:
            fontFamily = "Arial, sans-serif";
            fontDescription = "Arial";
            break;
        case 4:
            fontFamily = "Times New Roman, serif";
            fontDescription = "Times New Roman";
            break;
        case 5:
            fontFamily = "MSDOS, monospace";
            fontDescription = "MSDOS";
            break;
        default:
            fontFamily = "SynergySans, sans-serif";
            fontDescription = "SynergySans (по умолчанию)";
    }

    string pageText = "Университет «Синерги́я» (Московский финансово-промышленный университет «Синергия») — российское частное высшее учебное заведение, основанное в 1995 году в Москве. Юридическое наименование — Негосударственное образовательное частное учреждение высшего образования «Московский финансово-промышленный университет „Синергия“».\n\n"
    "В 2023 году МФПУ «Синергия» стал крупнейшим университетом России по количеству студентов и иностранных студентов.\n\n"
    "Университет готовит специалистов по 21 направлению магистратуры, 12 направлениям специалитета, 29 направлениям бакалавриата, 34 специальностям среднего профессионального образования, 30 научным специальностям в аспиранутре на 53 кафедрах и 38 факультетах.\n\n"
    "По итогам мониторинга качества высшего образования, проведённого Министерством образования и науки Российской Федерации в декабре 2012 года, университет был признан эффективно работающим вузом, а также повторно — в октябре 2013 года.";
    
    ofstream cssFile("style.css");
    if (cssFile.is_open()) {
        cssFile << "/* CSS файл для страницы университета \"Синергия\" */\n";
        cssFile << "/* Используемый шрифт: " << fontDescription << " */\n\n";
        cssFile << "body {\n";
        cssFile << "    font-family: " << fontFamily << ";\n";
        cssFile << "    background-color: #f5f5f5;\n";
        cssFile << "    color: #333;\n";
        cssFile << "    max-width: 900px;\n";
        cssFile << "    margin: 0 auto;\n";
        cssFile << "    padding: 30px 20px;\n";
        cssFile << "    line-height: 1.6;\n";
        cssFile << "}\n\n";
        cssFile << "h1 {\n";
        cssFile << "    font-family: " << fontFamily << ";\n";
        cssFile << "    color: #003366;\n";
        cssFile << "    text-align: center;\n";
        cssFile << "    font-size: 2.5em;\n";
        cssFile << "    border-bottom: 3px solid #003366;\n";
        cssFile << "    padding-bottom: 15px;\n";
        cssFile << "    margin-bottom: 30px;\n";
        cssFile << "    letter-spacing: 3px;\n";
        cssFile << "}\n\n";
        cssFile << "p {\n";
        cssFile << "    font-family: " << fontFamily << ";\n";
        cssFile << "    font-size: 1.1em;\n";
        cssFile << "    text-align: justify;\n";
        cssFile << "    margin-bottom: 20px;\n";
        cssFile << "    text-indent: 30px;\n";
        cssFile << "}\n\n";
        cssFile << ".container {\n";
        cssFile << "    background-color: white;\n";
        cssFile << "    padding: 30px;\n";
        cssFile << "    border-radius: 10px;\n";
        cssFile << "    box-shadow: 0 4px 8px rgba(0,0,0,0.1);\n";
        cssFile << "}\n\n";
        cssFile << ".footer {\n";
        cssFile << "    margin-top: 40px;\n";
        cssFile << "    text-align: center;\n";
        cssFile << "    font-size: 0.85em;\n";
        cssFile << "    color: #888;\n";
        cssFile << "    border-top: 1px solid #ddd;\n";
        cssFile << "    padding-top: 20px;\n";
        cssFile << "}\n";
        cssFile.close();
        cout << "CSS файл 'style.css' успешно создан!\n";
    } else {
        cerr << "Ошибка: не удалось создать CSS файл!\n";
        return;
    }
    
    ofstream htmlFile("index.html");
    if (htmlFile.is_open()) {
        htmlFile << "<!DOCTYPE html>\n";
        htmlFile << "<html lang=\"ru\">\n";
        htmlFile << "<head>\n";
        htmlFile << "    <meta charset=\"UTF-8\">\n";
        htmlFile << "    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n";
        htmlFile << "    <title>Синергия</title>\n";
        htmlFile << "    <link rel=\"stylesheet\" href=\"style.css\">\n";
        htmlFile << "</head>\n";
        htmlFile << "<body>\n";
        htmlFile << "    <div class=\"container\">\n";
        htmlFile << "        <h1>Синергия</h1>\n";
        
        size_t pos = 0;
        string delimiter = "\n\n";
        string text = pageText;
        while ((pos = text.find(delimiter)) != string::npos) {
            string paragraph = text.substr(0, pos);
            if (!paragraph.empty()) {
                htmlFile << "        <p>" << paragraph << "</p>\n";
            }
            text.erase(0, pos + delimiter.length());
        }
        if (!text.empty()) {
            htmlFile << "        <p>" << text << "</p>\n";
        }
        
        htmlFile << "        <div class=\"footer\">\n";
        htmlFile << "            <p>Используемый шрифт: " << fontDescription << "</p>\n";
        htmlFile << "        </div>\n";
        htmlFile << "    </div>\n";
        htmlFile << "</body>\n";
        htmlFile << "</html>\n";
        htmlFile.close();
        cout << "HTML файл 'index.html' успешно создан!\n";
    } else {
        cerr << "Ошибка: не удалось создать HTML файл!\n";
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    
    cout << "===========================================\n";
    cout << "  Генератор HTML-страницы \"Синергия\"\n";
    cout << "===========================================\n\n";
    cout << "Выберите вариант генерации:\n\n";
    cout << "  1. SynergySans (по умолчанию)\n";
    cout << "  2. Calibri\n";
    cout << "  3. Arial\n";
    cout << "  4. Times New Roman\n";
    cout << "  5. MSDOS\n\n";
    cout << "Введите номер варианта (1-5): ";
    
    int choice;
    cin >> choice;
    
    if (cin.fail() || choice < 1 || choice > 5) {
        clearInput();
        cout << "\nНекорректный ввод. Будет использован вариант по умолчанию (SynergySans).\n";
        choice = 1;
    }
    
    cout << "\nВы выбрали вариант: ";
    switch(choice) {
        case 1: cout << "SynergySans"; break;
        case 2: cout << "Calibri"; break;
        case 3: cout << "Arial"; break;
        case 4: cout << "Times New Roman"; break;
        case 5: cout << "MSDOS"; break;
    }
    cout << "\n\nГенерация файлов...\n\n";
    
    generateFiles(choice);
    
    cout << "\nФайлы успешно сгенерированы!\n";
    cout << "Откройте 'index.html' в браузере для просмотра.\n";
    cout << "===========================================\n";
    
    return 0;
}