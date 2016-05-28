#include "13.49.h"

int main() {
    Message first_mail("hello");
    Message signin_mail("welcome to cpp");
    Folder mail_box;

    first_mail.save(mail_box);
    sigin_mail.save(mail_box);
    mail_box.print_debug();

    first_mail = move(signin_mail);
    mail_box.print_debug();

    return 0;
}
