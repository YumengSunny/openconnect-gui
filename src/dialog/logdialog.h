/*
 * Copyright (C) 2014 Red Hat
 *
 * This file is part of openconnect-gui.
 *
 * openconnect-gui is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <QDialog>

#include "base/logger.h"
namespace Ui {
class LogDialog;
}

class LogDialog : public QDialog {
    Q_OBJECT
public:
    LogDialog(QWidget* parent = 0);
    ~LogDialog();

public slots:
    void append(const Logger::Message& message);

protected slots:
    void closeEvent(QCloseEvent* event) override;

private slots:
    void reject() override;

    void on_pushButtonClear_clicked();
    void on_pushButtonSelectAll_clicked();
    void on_pushButtonCopy_clicked();

    void onItemSelectionChanged();

signals:
    void clear_log(void);
    void clear_logdialog(void);

private:
    void loadSettings();
    void saveSettings();

    Ui::LogDialog* ui;
};
