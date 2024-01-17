using System;

namespace visualizerGUI {

    class Program { 
    
        static void Main(string[] args)
        {
            // Create and run the main window
            var app = new Application();
            app.Run(new MainWindow());
        }
    }
}