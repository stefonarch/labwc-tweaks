#include "mouse.h"
#include "environment.h"
#include "find-themes.h"
#include "macros.h"
#include "settings.h"
#include "./ui_mouse.h"

Mouse::Mouse(QWidget *parent) : QWidget(parent), ui(new Ui::pageMouse)
{
    ui->setupUi(this);
}

Mouse::~Mouse()
{
    delete ui;
}

void Mouse::activate()
{
    /* Cursor Theme */
    QStringList cursorThemes = findIconThemes(LAB_ICON_THEME_TYPE_CURSOR);
    ui->cursorTheme->addItems(cursorThemes);
    ui->cursorTheme->setCurrentIndex(cursorThemes.indexOf(getStr("XCURSOR_THEME")));

    /* Cursor Size */
    ui->cursorSize->setValue(getInt("XCURSOR_SIZE"));

    /* Natural Scroll */
    ui->naturalScroll->setChecked(getBool("/labwc_config/libinput/device/naturalScroll"));

    /* Left Handed */
    ui->leftHanded->setChecked(getBool("/labwc_config/libinput/device/leftHanded"));

    /* pointerSpeed */
    ui->pointerSpeed->setValue(getInt("/labwc_config/libinput/device/pointerSpeed"));

    /* accelProfile */
//    ui->accelProfile->setCurrentIndex("/labwc_config/libinput/device/accelProfile"));

    /* Tap to click */
    ui->tap->setChecked(getBool("/labwc_config/libinput/device/tap"));

    /* Tap Button Map */

    /* Drag Lock */
    ui->tapAndDrag->setChecked(getBool("/labwc_config/libinput/device/tapAndDrag"));

    /* Drag Lock */
    ui->dragLock->setChecked(getBool("/labwc_config/libinput/device/dragLock"));

    /* 3 Finger Drag */
    ui->threeFingerDrag->setChecked(getBool("/labwc_config/libinput/device/threeFingerDrag"));

    /* Middle Emulation */
    ui->middleEmulation->setChecked(getBool("/labwc_config/libinput/device/middleEmulation"));

    /* Disable While Typing */
    ui->disableWhileTyping->setChecked(getBool("/labwc_config/libinput/device/disableWhileTyping"));
}

void Mouse::onApply()
{
    /* ~/.config/labwc/rc.xml */
    setBool("/labwc_config/libinput/device/naturalScroll", ui->naturalScroll->isChecked());
    setBool("/labwc_config/libinput/device/leftHanded", ui->leftHanded->isChecked());
    setInt("/labwc_config/libinput/device/pointerSpeed", ui->pointerSpeed->value());// FIXME is float
    setBool("/labwc_config/libinput/device/tap", ui->tap->isChecked());
    // tab button map here
    setBool("/labwc_config/libinput/device/tapAndDrag", ui->tapAndDrag->isChecked());
    setBool("/labwc_config/libinput/device/dragLock", ui->dragLock->isChecked());
    setBool("/labwc_config/libinput/device/threeFingerDrag", ui->threeFingerDrag->isChecked());
    setBool("/labwc_config/libinput/device/middleEmulation", ui->middleEmulation->isChecked());
    setBool("/labwc_config/libinput/device/disableWhileTyping", ui->disableWhileTyping->isChecked());

    /* ~/.config/labwc/environment */
    environmentSet("XCURSOR_THEME", TEXT(ui->cursorTheme));
    environmentSetInt("XCURSOR_SIZE", ui->cursorSize->value());
}
