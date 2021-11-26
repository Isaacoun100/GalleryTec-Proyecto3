#include "ReadWrite.h"

string ReadWrite::getPWD(){
    char tmp[256];
    getcwd(tmp, 256);
    string temporal=tmp;
    temporal=temporal.erase(temporal.size()-17,temporal.size());
    return temporal;
}

string ReadWrite::readFile(string path) {
    string text, result;
    string temporal=getPWD()+path;

    ifstream stream(temporal);

    if (stream.is_open()) {
        while (getline(stream, text)) {
            result.append(text + '\n');
        }
    }

    getline(stream, text);

    stream.close();
    return result;
}

void ReadWrite::writeFile(string path, string result) {

    string temporal=getPWD()+path;
    ofstream stream(temporal);

    if(stream.fail()){
        cout << "Unable to locate file to write " << endl;
    }

    stream<<result;
    stream.close();

}

void ReadWrite::clearFile(string path) {
    writeFile(path,"");
}
