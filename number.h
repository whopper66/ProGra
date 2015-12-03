#ifndef NUMBER_H
#define NUMBER_H

#include <QPoint>
#include <QPointF>

class Number {
private:
	int value;
	bool selected;

	QPointF position;
	/* pozycja numeru na ekranie, proponuję współrzędne z zakresu
     * [0..1] + skalowanie w funkcji rysującej */

public:
	int getValue() const;
	bool isSelected() const;
	const QPointF & getPosition() const;
	void setSelected(bool selected);
	void toggleSelected();

	Number();
	Number(int value, const QPointF &position);
};

#endif // NUMBER_H
