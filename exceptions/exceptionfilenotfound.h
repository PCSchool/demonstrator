#ifndef EXCEPTIONFILENOTFOUND_H
#define EXCEPTIONFILENOTFOUND_H

#include <QException>

class ExceptionFileNotFound : public QException
{
public:
    void raise() const {throw * this;}
    ExceptionFileNotFound *clone() const {return new ExceptionEmptyForm(*this);}
};


#endif // EXCEPTIONFILENOTFOUND_H
