#ifndef CONVERTER_H
#define CONVERTER_H

#include <QString>
#include <QFileInfoList>
#include <QStringList>
#include <QJsonArray>
#include <QJsonObject>
#include <QHash>

#include "mainwindow.h"
//#include "convertexception.h"

class Converter
{
public:
    Converter(QString inPath, QString outPath, MainWindow* window, Settings* settings);
    
    QStringList getFileNameList();
	void logComponents();
	bool convert(uint index);
	bool convertAll();
	void setStop();
	
private:
    QJsonArray components;
    QJsonObject tables;
    QString inPath;
    QString outPath;
    QByteArray json;
    QFileInfoList fileList;
	MainWindow* window;
	Settings* settings;
	
	QHash<int, QByteArray> componentDllCodes;
	bool stop; // stops execution if set to true
	bool error; // some error occurred
    
    void loadConfig();
	void setFileList();
	
	QString convertSingle(QFileInfo file);
	
	QByteArray clearComments(QByteArray json);
	QJsonValue decodePresetHeader(QByteArray blob);
	QJsonArray decodeComponents(QByteArray blob, uint offset);
	int getComponentIndex(uint code, QByteArray blob, uint offset);
	QByteArray postProcess(QJsonDocument preset);
};

#endif // CONVERTER_H
