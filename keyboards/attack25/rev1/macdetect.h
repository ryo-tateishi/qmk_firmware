bool macos_check(void);

#define MACOS_CHECK if (!macos_checked) {MAC_mode = macos_check(); macos_checked = true; }
