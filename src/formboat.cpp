/*
 * Copyright (C) Robert Lainé & Jeremy Lainé
 * See AUTHORS file for a full list of contributors.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include "formboat.h"
#include "boatdef-panel.h"
#include "sailcpp/hullworker.h"
#include "sailcpp/sailworker.h"
#include "sailcpp/rigworker.h"
#include "sailwriter-xml.h"

#include <QApplication>
#include <QLayout>
#include <QMenuBar>
#include <QFileInfo>
#include <QSplitter>

/**
 * The constructor.
 *
 * @param parent the parent widget
 */
CFormBoat::CFormBoat(QWidget *parent)
    : CFormMain(parent)
{
    // create main widget
    setupMainWidget();

    // create menu bar
    setupMenuBar();

    // set language
    connect(qApp, SIGNAL(languageChanged()),
            this, SLOT(languageChange()));
    languageChange();

    // set initial definition
    setDef(def);
}


/**
 * Adds a new element to the boat.
 *
 * @param newfile name of the file to add
 */
void CFormBoat::add(const QString &newfile)
{
    CBoatElement element;

    if (CSailDefXmlWriter().isDocument(newfile))
    {
        CSailDef saildef = CSailDefXmlWriter().read(newfile);
        (CPanelGroup&)element = CSailWorker(saildef).makeSail();
        element.type = SAILDEF;
    }
    else if (CHullDefXmlWriter().isDocument(newfile))
    {
        CHullDef hulldef = CHullDefXmlWriter().read(newfile);
        (CPanelGroup&)element = CHullWorker(hulldef).makeHull();
        element.type = HULLDEF;
    }
    else if (CRigDefXmlWriter().isDocument(newfile))
    {
        CRigDef rigdef = CRigDefXmlWriter().read(newfile);
        (CPanelGroup&)element = CRigWorker(rigdef).makeRig();
        element.type = RIGDEF;
    }
    else if (CPanelGroupXmlWriter().isDocument(newfile))
    {
        (CPanelGroup&)element = CPanelGroupXmlWriter().read(newfile);
        element.type = PANELGROUP;
    }
    else
    {
        throw std::invalid_argument("CFormBoat::add : unknown document type");
    }
    element.filename = newfile.toStdString();
    def.push_back(element);
    setDef(def);
}


/**
 * Sets the strings of the subwidgets using the current
 * language.
 */
void CFormBoat::languageChange()
{
    setWindowTitle( tr("boat") );
    menuAdd->setTitle( tr("&Add") );
    actionAddFile->setText( tr("file") );
}


bool CFormBoat::read(const QString &filename)
{
    try {
        setDef(writer.read(filename));
        return true;
    } catch (read_error const&) {
        return false;
    }
}


bool CFormBoat::write(const QString &filename)
{
    try {
        writer.write(def, filename);
        return true;
    } catch (write_error const&) {
        return false;
    }
}


/**
 * We got a new boat definition, update widgets.
 *
 * @param newdef The new boat definition
 */
void CFormBoat::setDef(const CBoatDef &newdef)
{
    def = newdef;
    defpanel->setDef(def);
    tabs->setObject(def.makePanelGroup());
}


/**
 * Creates the main widget
 */
void CFormBoat::setupMainWidget()
{
    tabs = new CSailViewerTabs(this);
    defpanel = new CBoatDefPanel(this);

    QSplitter *splitter = new QSplitter(Qt::Horizontal, this);
    splitter->addWidget(tabs);
    splitter->addWidget(defpanel);
    setCentralWidget(splitter);

    connect(defpanel, SIGNAL(signalUpdate(const CBoatDef& )), this, SLOT(slotUpdate(const CBoatDef& )));
}


/**
 * Creates the menu bar
 */
void CFormBoat::setupMenuBar()
{
    menuAdd = new QMenu(this);
    actionAddFile = menuAdd->addAction( "", this, SLOT( slotAdd() ) );
    addFileMenu(menuAdd);
}

/**
 * The file menu's "Add" item was clicked.
 */
void CFormBoat::slotAdd()
{
    QString filter = "Sailcut CAD files (";
    filter += QString("*") + CSailDefXmlWriter().fileExtension();
    filter += QString(" *") + CHullDefXmlWriter().fileExtension();
    filter += QString(" *") + CRigDefXmlWriter().fileExtension();
    filter += QString(" *") + CPanelGroupXmlWriter().fileExtension();
    filter += ")";

    QString newfile = QFileDialog::getOpenFileName(0, tr("Open"), "", filter);
    if ( !newfile.isNull() )
        add(newfile);
}


/**
 * The boat definition was modified by the user.
 *
 * @param newdef The new boat definition
 */
void CFormBoat::slotUpdate(const CBoatDef& newdef)
{
    setDef(newdef);
}


