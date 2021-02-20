package GoF.Behavioral.Command;

import java.util.Iterator;
import java.util.List;

/**
 * The goal is to implement a document editor here, which reads and writes,
 * copies and pastes.
 * 
 * The Command interface is responsible for executing the commands. The
 * OpenCommand asks the user for the name of the document, then opens that
 * document. The paste command must be passed a document as it's receiver.
 * 
 * The MacroCommand, keeps a list of commands that can be executed in an order
 * for example.
 */

class Document {
    public Document(String name) {

    }

    public void Open() {

    }

    public void Paste(){

    }

}

class Application {
    public void Add(Document doc) {

    }
}

interface Command {
    public void Execute();
};

abstract class OpenCommand implements Command {
    String _response;
    Application _application;

    public OpenCommand(Application app) {
        _application = app;
    };

    public void Execute() {
        String name = AskUser();
        if (name != null) {
            Document document = new Document(name);
            _application.Add(document);
            document.Open();
        }

    };

    protected abstract String AskUser();

};

class PasteCommand implements Command {
    Document _document;

    public PasteCommand(Document document) {
        _document = document;
    }

    public void Execute() {
        _document.Paste();
    };
};


class MacroCommand implements Command {
    List<Command> _cmds;
    void Add(Command command){
        _cmds.add(command);
    };
    void Remove(Command command){
        _cmds.remove(command);
    };

    public void Execute(){
        Iterator<Command> commands = _cmds.iterator();

        while (commands.hasNext()) {
            commands.next().Execute();
        }
    }   
