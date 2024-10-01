
# GunaCharts Readme - Modern WinForms Charting Library

Welcome to GunaCharts, a cutting-edge WinForms charting library that empowers developers to effortlessly create interactive and captivating data visualizations. With a wide array of chart types, responsive design for various screen sizes, real-time data capabilities, and the ability to blend multiple chart types, GunaCharts revolutionizes data visualization.

## Chart Types

GunaCharts offers an extensive selection of 16 distinct chart types, allowing you to effectively convey insights from your data. The available chart types are shown below:

| Chart Type            | Description                                        |
|-----------------------|----------------------------------------------------|
| **Area**              | Plot data points and emphasize the cumulative total. |
| **Bar**               | Visually compare data across categories with bars. |
| **Bubble**            | Represent data points with varying circle sizes. |
| **Doughnut**          | Display data in a ring-shaped pie chart. |
| **HorizontalBar**     | Use horizontal bars for an alternative perspective. |
| **Line**              | Connect data points to reveal trends and patterns. |
| **Pie**               | Portray data as slices of a traditional pie chart. |
| **PolarArea**         | Arrange data points radially for a unique view. |
| **Radar**             | Present multivariate data points on a radar chart. |
| **Scatter**           | Scatter data points to identify relationships. |
| **Spline**            | Smoothed curve connects data points seamlessly. |
| **SplineArea**        | Blend spline curves with area charts for impact. |
| **StackedBar**        | Stack data categories for a holistic representation. |
| **StackedHorizontalBar** | Stack bars horizontally for engaging visuals. |
| **SteppedArea**       | Create a stepped area chart for distinct trends. |
| **SteppedLine**       | Illustrate data changes with stepped line segments. |

## Responsive Design

With GunaCharts, your data visualizations seamlessly adapt to diverse screen sizes. Whether your users view your application on a large monitor or a mobile device, GunaCharts' responsive design ensures that charts remain clear and usable.

## Live Charts

Easily create real-time data dashboards using GunaCharts. The library simplifies the creation of dynamic data displays that update in real-time, enabling effective monitoring of changing data patterns.

## Mixed Chart Types

GunaCharts empowers you to blend different chart types effortlessly. By combining chart types like Bar and Line/Area, you can craft unique visualizations that provide a comprehensive view of your data.

## Compatibility

GunaCharts seamlessly integrates with various .NET framework versions:
- .NET Framework v4.0 or higher
- .NET Core App 3.1 or higher
- .NET 6
- .NET 7

## Supported IDE

GunaCharts is designed for use with Visual Studio, starting from Visual Studio 2012 and higher versions.


## Installation via Package Manager Console

To integrate GunaCharts into your Visual Studio project using the Package Manager Console, follow these steps:

1. Open your Visual Studio project.
2. Go to `Tools` > `NuGet Package Manager` > `Package Manager Console`.
3. In the Package Manager Console, enter the following command:
   
   ```powershell
   Install-Package Guna.Charts.WinForms
   ```
4. Press Enter to execute the command. The package will be installed into your project.

## How to Use GunaCharts 
1. Begin by importing the required namespaces at the beginning of your Form class:

    ```csharp
    using System; 
    using System.Drawing; 
    using System.Windows.Forms; 
    using Guna.Charts.WinForms;
    ```

2. Create a new Form class that inherits from the `Form` class:

    ```csharp
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            InitializeGunaChart();
        }
    }
    ```

3. Inside the Form class, declare the variables needed for GunaCharts:

    ```csharp
    private GunaChart gunaChart;
    private GunaLineDataset gunaLineDataset;
    private GunaBarDataset gunaBarDataset;
    ```

4. Implement the `InitializeGunaChart` method, where we set up both bar and line charts:

    ```csharp
    private void InitializeGunaChart()
    {
        // Create a new instance of GunaChart
        gunaChart = new GunaChart();
        gunaChart.Dock = DockStyle.Fill;
        Controls.Add(gunaChart);
    
        // Set up GunaLineDataset
        gunaLineDataset = new GunaLineDataset();
        gunaLineDataset.Label = "Line";
        gunaLineDataset.LegendBoxFillColor = Color.DodgerBlue;
        gunaLineDataset.FillColor = Color.DodgerBlue;
        gunaLineDataset.BorderColor = Color.DodgerBlue;
        gunaLineDataset.YFormat = "Income {0:C}";
    
        // Set up GunaBarDataset
        gunaBarDataset = new GunaBarDataset();
        gunaBarDataset.Label = "Bar";
        gunaBarDataset.LegendBoxFillColor = Color.MediumSlateBlue;
        gunaBarDataset.FillColors.Add(Color.MediumSlateBlue);
        gunaBarDataset.FillColors.Add(Color.MediumPurple);
        gunaBarDataset.YFormat = "C";
    
        // Add the datasets to the Datasets collection of GunaChart
        gunaChart.Datasets.Add(gunaLineDataset);
        gunaChart.Datasets.Add(gunaBarDataset);
    
        // Generate data and labels for the datasets
        GenerateDataAndLabels();
    }
    ```

5. Define the `GenerateDataAndLabels` method to populate the datasets with data:

    ```csharp
    private void GenerateDataAndLabels()
    {
        // Sample labels for the x-axis representing months
        string[] monthLabels = { "January", "February", "March", "April", "May", "June", "July" };
    
        // Generate random data for the datasets    
        var random = new Random();
        foreach (var label in monthLabels)
        {
            gunaLineDataset.DataPoints.Add(new LPoint()
            {
                Label = label,
                Y = random.Next(10, 100),
            });
    
            gunaBarDataset.DataPoints.Add(new LPoint()
            {
                Label = label,
                Y = random.Next(10, 100),
            });
        }
    }
    ```

6. Run your application.

### Exporting Charts

Capture your visually appealing charts with GunaCharts' export feature. Simply:

- Export the chart as an image using the save dialog::
    ```csharp
    gunaChart.Export();
    ```

- Export the chart to a specific file path:
    ```csharp
    gunaChart.Export("C:\chart.png");
    ```

- Export the chart with a specific image format (e.g., PNG):
    ```csharp
    gunaChart.Export("C:\chart.png", System.Drawing.Imaging.ImageFormat.Png);
    ```


### Activating Zoom Functionality

GunaCharts provides an immersive zooming experience to magnify specific chart areas for a closer analysis. You can enable and configure zooming with the following steps:

- Activate Zoom Mode (Choose one):
   Zoom along the X-axis:
   ```csharp
   gunaChart.Zoom = ZoomMode.X;
   ```

   Zoom along the Y-axis:
   ```csharp
   gunaChart.Zoom = ZoomMode.Y;
   ```

   Zoom along both X and Y axes:
   ```csharp
   gunaChart.Zoom = ZoomMode.XY;
   ```

- To deactivate zoom functionality:
   ```csharp
   gunaChart.Zoom = ZoomMode.None;
   ```
Zoom actions can be performed using the mouse wheel or pinch gestures if your device supports touch screen interaction. Additionally, the zoom functionality of GunaCharts can be achieved through various methods:

- Zoom In:
    ```csharp
    gunaChart.ZoomIn();
    ```

- Zoom Out:
    ```csharp
    gunaChart.ZoomOut();
    ```
- Reset Zoom
    ```csharp
    gunaChart.ResetZoom();
    ```
 

### Handling Rendering Issues

If you encounter issues with chart rendering, trigger a manual update to ensure smooth rendering:
```csharp
gunaChart.Update();
```

## Examples

Explore GunaChartExamples repository on GitHub to discover how to implement GunaCharts in your projects:
- [GunaChartExamples Repository](https://github.com/sobatdata/GunaChartExamples)

## Useful Links

Learn more about GunaCharts and its capabilities through these links:
- [Homepage](https://gunaui.com/)
- [Demos](https://github.com/sobatdata/GunaChartExamples)
- [NuGet Profile](https://www.nuget.org/profiles/Sobatdata)
- [YouTube](https://www.youtube.com/@gunaui4933/)

Start using GunaCharts to elevate your WinForms data visualization and present insights in a compelling and informative manner.