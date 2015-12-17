#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "Levels/level1.h"
#include "Levels/level2.h"
#include "Levels/level3.h"

#include <QTimer>
#include <QVector>

#include <QDebug>

const int MAX_SUM = 16500;

class Gameplay : private QObject {
	Q_OBJECT

private:
	QTimer updateTimer;
	QTimer nextNumberTimer;
    QTimer levelCountdownTimer;

	QVector<Number> numbers;
	int sumOfNumbers;
	/* do sprawdzania, które sumy są osiągalne */
	int correctSum;
	/* tyle, ile gracz powinien uzyskać, nie mam pomysłu
     * na lepszą nazwę */
	bool *reachable;
	Level *currentLevel;

    int sumOfSelected() const;
	int findCorrectSum();
    void initialize();
    void pushNumber(const Number &n, bool pushToVec);
	void initializeNumbers();
	void deleteSelectedNumbers();
	void setNextNumberTimer();
    void setLevelCountdownTimer();
	//void iterateLevel();
    void prepare();

private slots:
    void addNumber();
    void update();
    void lose();

public:
	Gameplay();
	~Gameplay();

	int getNumbersCount() const;
    int getStartTime() const;
    int getTimeLeft() const;
	Number getNthNumber(int n) const;
    void handleUserClick(const QPointF &pos, const qreal CLICK_RADIUS);
    bool isTimed() const;
	void iterateLevel();
	//void setLevel(int);
	//const Level getLevel() const;
};

#endif // GAMEPLAY_H
