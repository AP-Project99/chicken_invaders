#include "Score.h"
#include <QFont>

Score::Score():playerScore(0)
{
    setPlainText(QString::number(playerScore));
    setDefaultTextColor(Qt::white);
    setFont(QFont("segoe script",15));
}
