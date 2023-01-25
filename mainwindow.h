#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    std::string generateSVGFile(QString text);
    void renderSVGFile(std::string svgText);

private slots:
    void btnEncodeClicked();
    void btnSaveSVGFileClicked();

private:
    Ui::MainWindow *ui;
    std::string m_svgText;
};
#endif // MAINWINDOW_H
