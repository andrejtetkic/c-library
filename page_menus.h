#ifndef PAGE_MENUS_H_INCLUDED
#define PAGE_MENUS_H_INCLUDED


void SignUp();
void landingPage();
void logIn();
void browse();
void hash_password(const char *password, const char *salt, char *hashed_password);
void generate_salt(char *salt);

#endif /* PAGE_MENUS_H_INCLUDED */