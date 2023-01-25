#include "mainwindow.h"
#include "qrcodegen.h"
#include "ui_mainwindow.h"

#include <QPainter>
#include <QPixmap>
#include <QSvgRenderer>
#include <QFileDialog>
#include <QFile>

using namespace qrcodegen;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

std::string MainWindow::generateSVGFile(QString text)
{
    QrCode qr0 = QrCode::encodeText(text.toStdString().c_str(), QrCode::Ecc::MEDIUM);
    std::string svg = qrcodegen::toSvgString(qr0, 4);
    return svg;
}

void MainWindow::renderSVGFile(std::string svgText)
{
    QByteArray svgData(svgText.c_str());
    QSvgRenderer renderer(svgData, this);

    QPixmap pixmap(400, 400);
    pixmap.fill(Qt::transparent);

    QPainter painter(&pixmap);
    renderer.render(&painter);

    ui->lblSVG->setPixmap(pixmap);
}

void MainWindow::btnEncodeClicked()
{
    m_svgText = generateSVGFile(ui->plainTextEdit->toPlainText());
    renderSVGFile(m_svgText);
}

void MainWindow::btnSaveSVGFileClicked()
{
    QString fileName = QFileDialog::getSaveFileName(
        this,
        tr("Save File"), QString(), tr("SVG Files (*.svg)")
    );
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream stream(&file);
            stream << QString::fromStdString(m_svgText);
            file.close();
        }
    }
}

