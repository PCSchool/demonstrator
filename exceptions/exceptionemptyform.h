#ifndef EXCEPTIONEMPTYFORM_H
#define EXCEPTIONEMPTYFORM_H

#include <QException>

class ExceptionEmptyForm : public QException
{
public:
    void raise() const {throw * this;}
    ExceptionEmptyForm *clone() const {return new ExceptionEmptyForm(*this);}
};

#endif // EXCEPTIONEMPTYFORM_H
