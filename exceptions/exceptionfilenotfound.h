#ifndef EXCEPTIONFILENOTFOUND_H
#define EXCEPTIONFILENOTFOUND_H

#include <QException>

class ExceptionFileNotFound : public QException
{
public:
    const QString error = "ExceptionFileNotFound: File couldnt be found. Possibly due to wrong directory or the file doesnt exist.";
    void raise() const {throw * this;}
    ExceptionFileNotFound *clone() const {return new ExceptionEmptyForm(*this);}
};


#endif // EXCEPTIONFILENOTFOUND_H
