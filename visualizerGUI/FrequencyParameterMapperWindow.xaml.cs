using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace visualizerGUI
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class FrequencyParameterMapperWindow : Window
    {
        public FrequencyParameterMapperWindow()
        {
            InitializeComponent();
        }

        private void Frame_Navigated(object sender, NavigationEventArgs e)
        {

        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {

            System.Diagnostics.Debug.WriteLine("Opening new frequency parameter mapper");

            FrequencyParameterMapperWindow frequencyParameterMapperWindow = new FrequencyParameterMapperWindow();
            frequencyParameterMapperWindow.Show();
        }
    }
}
