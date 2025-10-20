#include "my_string.h"

#ifdef __linux__
#define error_text "Unknown error"
static const char* error_messages_linux[] = {
    [0] = "Success",
    [EPERM] = "Operation not permitted",
    [ENOENT] = "No such file or directory",
    [ESRCH] = "No such process",
    [EINTR] = "Interrupted system call",
    [EIO] = "Input/output error",
    [ENXIO] = "No such device or address",
    [E2BIG] = "Argument list too long",
    [ENOEXEC] = "Exec format error",
    [EBADF] = "Bad file descriptor",
    [ECHILD] = "No child processes",
    [EAGAIN] = "Resource temporarily unavailable",
    [ENOMEM] = "Cannot allocate memory",
    [EACCES] = "Permission denied",
    [EFAULT] = "Bad address",
    [ENOTBLK] = "Block device required",
    [EBUSY] = "Device or resource busy",
    [EEXIST] = "File exists",
    [EXDEV] = "Invalid cross-device link",
    [ENODEV] = "No such device",
    [ENOTDIR] = "Not a directory",
    [EISDIR] = "Is a directory",
    [EINVAL] = "Invalid argument",
    [ENFILE] = "Too many open files in system",
    [EMFILE] = "Too many open files",
    [ENOTTY] = "Inappropriate ioctl for device",
    [ETXTBSY] = "Text file busy",
    [EFBIG] = "File too large",
    [ENOSPC] = "No space left on device",
    [ESPIPE] = "Illegal seek",
    [EROFS] = "Read-only file system",
    [EMLINK] = "Too many links",
    [EPIPE] = "Broken pipe",
    [EDOM] = "Numerical argument out of domain",
    [ERANGE] = "Numerical result out of range",
    [EDEADLK] = "Resource deadlock avoided",
    [ENAMETOOLONG] = "File name too long",
    [ENOLCK] = "No locks available",
    [ENOSYS] = "Function not implemented",
    [ENOTEMPTY] = "Directory not empty",
    [ELOOP] = "Too many levels of symbolic links",
    [ENOMSG] = "No message of desired type",
    [EIDRM] = "Identifier removed",
    [ECHRNG] = "Channel number out of range",
    [EL2NSYNC] = "Level 2 not synchronized",
    [EL3HLT] = "Level 3 halted",
    [EL3RST] = "Level 3 reset",
    [ELNRNG] = "Link number out of range",
    [EUNATCH] = "Protocol driver not attached",
    [ENOCSI] = "No CSI structure available",
    [EL2HLT] = "Level 2 halted",
    [EBADE] = "Invalid exchange",
    [EBADR] = "Invalid request descriptor",
    [EXFULL] = "Exchange full",
    [ENOANO] = "No anode",
    [EBADRQC] = "Invalid request code",
    [EBADSLT] = "Invalid slot",
    [EBFONT] = "Bad font file format",
    [ENOSTR] = "Device not a stream",
    [ENODATA] = "No data available",
    [ETIME] = "Timer expired",
    [ENOSR] = "Out of streams resources",
    [ENONET] = "Machine is not on the network",
    [ENOPKG] = "Package not installed",
    [EREMOTE] = "Object is remote",
    [ENOLINK] = "Link has been severed",
    [EADV] = "Advertise error",
    [ESRMNT] = "Srmount error",
    [ECOMM] = "Communication error on send",
    [EPROTO] = "Protocol error",
    [EMULTIHOP] = "Multihop attempted",
    [EDOTDOT] = "RFS specific error",
    [EBADMSG] = "Bad message",
    [EOVERFLOW] = "Value too large for defined data type",
    [ENOTUNIQ] = "Name not unique on network",
    [EBADFD] = "File descriptor in bad state",
    [EREMCHG] = "Remote address changed",
    [ELIBACC] = "Can not access a needed shared library",
    [ELIBBAD] = "Accessing a corrupted shared library",
    [ELIBSCN] = ".lib section in a.out corrupted",
    [ELIBMAX] = "Attempting to link in too many shared libraries",
    [ELIBEXEC] = "Cannot exec a shared library directly",
    [EILSEQ] = "Invalid or incomplete multibyte or wide character",
    [ERESTART] = "Interrupted system call should be restarted",
    [ESTRPIPE] = "Streams pipe error",
    [EUSERS] = "Too many users",
    [ENOTSOCK] = "Socket operation on non-socket",
    [EDESTADDRREQ] = "Destination address required",
    [EMSGSIZE] = "Message too long",
    [EPROTOTYPE] = "Protocol wrong type for socket",
    [ENOPROTOOPT] = "Protocol not available",
    [EPROTONOSUPPORT] = "Protocol not supported",
    [ESOCKTNOSUPPORT] = "Socket type not supported",
    [EOPNOTSUPP] = "Operation not supported",
    [EPFNOSUPPORT] = "Protocol family not supported",
    [EAFNOSUPPORT] = "Address family not supported by protocol",
    [EADDRINUSE] = "Address already in use",
    [EADDRNOTAVAIL] = "Cannot assign requested address",
    [ENETDOWN] = "Network is down",
    [ENETUNREACH] = "Network is unreachable",
    [ENETRESET] = "Network dropped connection on reset",
    [ECONNABORTED] = "Software caused connection abort",
    [ECONNRESET] = "Connection reset by peer",
    [ENOBUFS] = "No buffer space available",
    [EISCONN] = "Transport endpoint is already connected",
    [ENOTCONN] = "Transport endpoint is not connected",
    [ESHUTDOWN] = "Cannot send after transport endpoint shutdown",
    [ETOOMANYREFS] = "Too many references: cannot splice",
    [ETIMEDOUT] = "Connection timed out",
    [ECONNREFUSED] = "Connection refused",
    [EHOSTDOWN] = "Host is down",
    [EHOSTUNREACH] = "No route to host",
    [EALREADY] = "Operation already in progress",
    [EINPROGRESS] = "Operation now in progress",
    [ESTALE] = "Stale file handle",
    [EUCLEAN] = "Structure needs cleaning",
    [ENOTNAM] = "Not a XENIX named type file",
    [ENAVAIL] = "No XENIX semaphores available",
    [EISNAM] = "Is a named type file",
    [EREMOTEIO] = "Remote I/O error",
    [EDQUOT] = "Disk quota exceeded",
    [ENOMEDIUM] = "No medium found",
    [EMEDIUMTYPE] = "Wrong medium type",
    [ECANCELED] = "Operation canceled",
    [ENOKEY] = "Required key not available",
    [EKEYEXPIRED] = "Key has expired",
    [EKEYREVOKED] = "Key has been revoked",
    [EKEYREJECTED] = "Key was rejected by service",
    [EOWNERDEAD] = "Owner died",
    [ENOTRECOVERABLE] = "State not recoverable",
    [ERFKILL] = "Operation not possible due to RF-kill",
    [EHWPOISON] = "Memory page has hardware error",
};
#define ERROR_MESSAGES error_messages_linux

#elif __APPLE__
#define error_text "Unknown error:"
#define error_107 "define error_text"
static const char* error_messages_mac[] = {
    [0] = "Undefined error: 0",
    [EPERM] = "Operation not permitted",
    [ENOENT] = "No such file or directory",
    [ESRCH] = "No such process",
    [EINTR] = "Interrupted system call",
    [EIO] = "Input/output error",
    [ENXIO] = "Device not configured",
    [E2BIG] = "Argument list too long",
    [ENOEXEC] = "Exec format error",
    [EBADF] = "Bad file descriptor",
    [ECHILD] = "No child processes",
    [EDEADLK] = "Resource deadlock avoided",
    [ENOMEM] = "Cannot allocate memory",
    [EACCES] = "Permission denied",
    [EFAULT] = "Bad address",
    [ENOTBLK] = "Block device required",
    [EBUSY] = "Resource busy",
    [EEXIST] = "File exists",
    [EXDEV] = "Cross-device link",
    [ENODEV] = "Operation not supported by device",
    [ENOTDIR] = "Not a directory",
    [EISDIR] = "Is a directory",
    [EINVAL] = "Invalid argument",
    [ENFILE] = "Too many open files in system",
    [EMFILE] = "Too many open files",
    [ENOTTY] = "Inappropriate ioctl for device",
    [ETXTBSY] = "Text file busy",
    [EFBIG] = "File too large",
    [ENOSPC] = "No space left on device",
    [ESPIPE] = "Illegal seek",
    [EROFS] = "Read-only file system",
    [EMLINK] = "Too many links",
    [EPIPE] = "Broken pipe",
    [EDOM] = "Numerical argument out of domain",
    [ERANGE] = "Result too large",
    [EAGAIN] = "Resource temporarily unavailable",
    [EINPROGRESS] = "Operation now in progress",
    [EALREADY] = "Operation already in progress",
    [ENOTSOCK] = "Socket operation on non-socket",
    [EDESTADDRREQ] = "Destination address required",
    [EMSGSIZE] = "Message too long",
    [EPROTOTYPE] = "Protocol wrong type for socket",
    [ENOPROTOOPT] = "Protocol not available",
    [EPROTONOSUPPORT] = "Protocol not supported",
    [ESOCKTNOSUPPORT] = "Socket type not supported",
    [ENOTSUP] = "Operation not supported",
    [EPFNOSUPPORT] = "Protocol family not supported",
    [EAFNOSUPPORT] = "Address family not supported by protocol family",
    [EADDRINUSE] = "Address already in use",
    [EADDRNOTAVAIL] = "Can't assign requested address",
    [ENETDOWN] = "Network is down",
    [ENETUNREACH] = "Network is unreachable",
    [ENETRESET] = "Network dropped connection on reset",
    [ECONNABORTED] = "Software caused connection abort",
    [ECONNRESET] = "Connection reset by peer",
    [ENOBUFS] = "No buffer space available",
    [EISCONN] = "Socket is already connected",
    [ENOTCONN] = "Socket is not connected",
    [ESHUTDOWN] = "Can't send after socket shutdown",
    [ETOOMANYREFS] = "Too many references: can't splice",
    [ETIMEDOUT] = "Operation timed out",
    [ECONNREFUSED] = "Connection refused",
    [ELOOP] = "Too many levels of symbolic links",
    [ENAMETOOLONG] = "File name too long",
    [EHOSTDOWN] = "Host is down",
    [EHOSTUNREACH] = "No route to host",
    [ENOTEMPTY] = "Directory not empty",
    [EPROCLIM] = "Too many processes",
    [EUSERS] = "Too many users",
    [EDQUOT] = "Disc quota exceeded",
    [ESTALE] = "Stale NFS file handle",
    [EREMOTE] = "Too many levels of remote in path",
    [EBADRPC] = "RPC struct is bad",
    [ERPCMISMATCH] = "RPC version wrong",
    [EPROGUNAVAIL] = "RPC prog. not avail",
    [EPROGMISMATCH] = "Program version wrong",
    [EPROCUNAVAIL] = "Bad procedure for program",
    [ENOLCK] = "No locks available",
    [ENOSYS] = "Function not implemented",
    [EFTYPE] = "Inappropriate file type or format",
    [EAUTH] = "Authentication error",
    [ENEEDAUTH] = "Need authenticator",
    [EPWROFF] = "Device power is off",
    [EDEVERR] = "Device error",
    [EOVERFLOW] = "Value too large to be stored in data type",
    [EBADEXEC] = "Bad executable (or shared library)",
    [EBADARCH] = "Bad CPU type in executable",
    [ESHLIBVERS] = "Shared library version mismatch",
    [EBADMACHO] = "Malformed Mach-o file",
    [ECANCELED] = "Operation canceled",
    [EIDRM] = "Identifier removed",
    [ENOMSG] = "No message of desired type",
    [EILSEQ] = "Illegal byte sequence",
    [ENOATTR] = "Attribute not found",
    [EBADMSG] = "Bad message",
    [EMULTIHOP] = "EMULTIHOP (Reserved)",
    [ENODATA] = "No message available on STREAM",
    [ENOLINK] = "ENOLINK (Reserved)",
    [ENOSR] = "No STREAM resources",
    [ENOSTR] = "Not a STREAM",
    [EPROTO] = "Protocol error",
    [ETIME] = "STREAM ioctl timeout",
    [EOPNOTSUPP] = "Operation not supported on socket",
    [ENOPOLICY] = "Policy not found",
    [ENOTRECOVERABLE] = "State not recoverable",
    [EOWNERDEAD] = "Previous owner died",
    [EQFULL] = "Interface output queue is full",
    [MAX_ERRNO] = "Capabilities insufficient"};
#define ERROR_MESSAGES error_messages_mac
#endif

static int parsing(char* str, const char* format, int i, int* j, va_list args);
static format_options parse_format_options(const char* format, int* i);
static void apply_width(char* str, int* j, format_options opts, int content_len,
                        int is_number);
static void handle_char(char* str, int* j, va_list args, format_options opts);
static void handle_int(char* str, int* j, va_list args, format_options opts);
static void handle_float_eE(char* str, int* j, va_list args,
                            format_options opts, char specifier);
static void handle_float_f(char* str, int* j, va_list args,
                           format_options opts);
static void handle_float_gG(char* str, int* j, va_list args,
                            format_options opts, char specifier);
static void handle_string(char* str, int* j, va_list args, format_options opts);
static void handle_unsigned_o(char* str, int* j, va_list args,
                              format_options opts);
static void handle_unsigned_u(char* str, int* j, va_list args,
                              format_options opts);
static void handle_unsigned_xX(char* str, int* j, va_list args,
                               format_options opts, char specifier);
static void handle_pointer(char* str, int* j, va_list args,
                           format_options opts);
static void handle_count(int* j, va_list args);
static void handle_percent(char* str, int* j, format_options opts);
static void reverse_buffer(char* buffer, int length);
static void handle_float_special_cases(double num, char* buffer, int* index,
                                       char specifier);
static int format_number_string(char* buffer, long num, int base,
                                int uppercase);
static int format_unsigned_string(char* buffer, unsigned long num, int base,
                                  int uppercase);

my_size_t my_strlen(const char* string) {
  int len = 0;
  int i = 0;
  while (string[i] != '\0') {
    i = i + 1;
  }
  len = i;

  return len;
}

void* my_memchr(const void* str, int c, my_size_t n) {
  const unsigned char* ptr = (const unsigned char*)str;
  unsigned char target = (unsigned char)c;
  void* result = my_NULL;

  if (str != my_NULL && n > 0) {
    my_size_t i = 0;
    int is_found = 0;

    while (i < n && is_found == 0) {
      if (ptr[i] == target) {
        result = (void*)(ptr + i);
        is_found = 1;
      }
      i++;
    }
  }

  return result;
}

int my_memcmp(const void* str1, const void* str2, my_size_t n) {
  const unsigned char* p1 = (const unsigned char*)str1;

  const unsigned char* p2 = (const unsigned char*)str2;

  my_size_t i = 0;
  int diff_found = 0;

  int diff = 0;

  while (i < n && diff_found == 0) {
    if (p1[i] != p2[i]) {
      diff = p1[i] - p2[i];
      diff_found = 1;
    }
    i++;
  }
  return diff;
}

void* my_memcpy(void* dest, const void* src, my_size_t n) {
  unsigned char* dest1 = (unsigned char*)dest;

  const unsigned char* src1 = (const unsigned char*)src;

  if (src != my_NULL && n > 0) {
    for (my_size_t i = 0; i < n; i++) {
      dest1[i] = src1[i];
    }
  }

  return dest1;
}

void* my_memset(void* str, int c, my_size_t n) {
  unsigned char* str1 = (unsigned char*)str;

  if (str != my_NULL && n > 0) {
    for (my_size_t i = 0; i < n; i++) {
      str1[i] = c;
    }
  }
  return str;
}

char* my_strncat(char* dest, const char* src, my_size_t n) {
  my_size_t len_dest = my_strlen(dest);
  my_size_t i = len_dest;
  my_size_t k = 0;
  while (i < len_dest + n) {
    dest[i] = src[k];
    k++;
    i++;
  }
  dest[i] = '\0';
  return dest;
}

int my_strncmp(const char* str1, const char* str2, my_size_t n) {
  int diff = 0;

  if (n != 0) {
    int diff_found = 0;

    my_size_t i = 0;
    while (i < n && diff_found == 0) {
      if (str1[i] != str2[i]) {
        diff = str1[i] - str2[i];
        diff_found = 1;
      }
      i++;
    }
  }
  return diff;
}

const char* my_strerror(int error_num) {
  static char unknown_error[50];
  const char* res;

  if (error_num < 0 || error_num > MAX_ERRNO ||
      ERROR_MESSAGES[error_num] == NULL ||
      ERROR_MESSAGES[error_num][0] == '\0') {
    snprintf(unknown_error, sizeof(unknown_error), "%s %d", error_text,
             error_num);

    res = unknown_error;
  } else {
    res = ERROR_MESSAGES[error_num];
  }

  return res;
}

char* my_strncpy(char* dest, const char* src, my_size_t n) {
  if (dest != my_NULL && src != my_NULL && n != 0) {
    my_size_t i = 0;
    int src_end_found = 0;

    while (i < n) {
      if (src_end_found == 0 && src[i] == '\0') {
        src_end_found = 1;
      }
      if (src_end_found == 1) {
        dest[i] = '\0';

      } else {
        dest[i] = src[i];
      }
      i++;
    }
  }
  return dest;
}

char* my_strpbrk(const char* str1, const char* str2) {
  char* res = my_NULL;
  if (str1 != my_NULL && str2 != my_NULL) {
    my_size_t str1_len = my_strlen(str1);
    my_size_t str2_len = my_strlen(str2);
    my_size_t i = 0;
    my_size_t j = 0;
    int match_found = 0;
    while (i < str1_len && match_found == 0) {
      while (j < str2_len && match_found == 0) {
        if (str1[i] == str2[j]) {
          match_found = 1;
          res = (char*)(str1 + i);
        }
        j++;
      }
      j = 0;
      i++;
    }
  }

  return res;
}

char* my_strchr(const char* str, int c) {
  char* res = my_NULL;

  if (str != my_NULL) {
    my_size_t i = 0;
    int match_found = 0;
    while (str[i] != '\0' && match_found == 0) {
      if (str[i] == (char)c) {
        res = (char*)(str + i);
        match_found = 1;
      }
      i++;
    }
    if (match_found == 0 && (char)c == '\0') {
      res = (char*)(str + i);
    }
  }

  return res;
}

char* my_strrchr(const char* str, int c) {
  char* res = my_NULL;

  if (str != my_NULL) {
    my_size_t i = 0;
    while (str[i] != '\0') {
      if (str[i] == (char)c) {
        res = (char*)(str + i);
      }
      i++;
    }
    if ((char)c == '\0') {
      res = (char*)(str + i);
    }
  }

  return res;
}

my_size_t my_strcspn(const char* str1, const char* str2) {
  my_size_t res = 0;

  if (str1 != my_NULL && str2 != my_NULL && str2[0] != '\0') {
    my_size_t i = 0;
    my_size_t j = 0;
    int match_found = 0;

    while (str1[i] != '\0' && match_found == 0) {
      while (str2[j] != '\0' && match_found == 0) {
        if (str1[i] == str2[j]) {
          match_found = 1;
          res = i;
        }
        j++;
      }
      j = 0;
      i++;
    }
    if (match_found == 0) {
      res = i;
    }
  } else if (str1 != my_NULL && (str2 == my_NULL || str2[0] == '\0')) {
    res = my_strlen(str1);
  }
  return res;
}

char* my_strstr(const char* haystack, const char* needle) {
  char* res = my_NULL;
  int error_found = 0;

  if (needle == my_NULL || *needle == '\0') {
    res = (char*)haystack;
    error_found = 1;
  }

  if (error_found == 0 && (haystack == my_NULL || *haystack == '\0')) {
    res = my_NULL;
    error_found = 1;
  }

  if (error_found == 0) {
    my_size_t haystack_len = my_strlen(haystack);
    my_size_t needle_len = my_strlen(needle);
    if (needle_len > haystack_len) {
      res = my_NULL;
      error_found = 1;
    }
    if (error_found == 0) {
      my_size_t i = 0;

      while (i <= haystack_len - needle_len && res == my_NULL) {
        my_size_t j = 0;
        int maybe_match = 1;
        while (j < needle_len && maybe_match == 1) {
          if (haystack[i + j] != needle[j]) {
            maybe_match = 0;
          }
          j++;
        }
        if (maybe_match == 1) {
          res = (char*)(haystack + i);
        }
        i++;
      }
    }
  }
  return res;
}

char* my_strtok(char* string, const char* delim) {
  static char* saved_string = my_NULL;

  char* result = my_NULL;

  if (string == my_NULL) {
    string = saved_string;
  }

  if (string != my_NULL) {
    my_size_t i = 0;
    my_size_t str_len = my_strlen(string);
    my_size_t delim_len = my_strlen(delim);
    int token_found = 0;

    while (i < str_len && token_found == 0) {
      int is_delim = 0;
      my_size_t j = 0;

      while (j < delim_len && is_delim == 0) {
        if (string[i] == delim[j]) {
          is_delim = 1;
        }
        j++;
      }

      if (is_delim == 0) {
        token_found = 1;

      } else {
        i++;
      }
    }
    int processing_complete = 0;

    if (i >= str_len || string[i] == '\0') {
      saved_string = my_NULL;

      processing_complete = 1;
    }

    if (processing_complete == 0) {
      char* token_start = string + i;

      my_size_t token_length = 0;
      int end_found = 0;

      while (i + token_length < str_len && end_found == 0) {
        int is_delim = 0;
        my_size_t k = 0;

        while (k < delim_len && is_delim == 0) {
          if (string[i + token_length] == delim[k]) {
            is_delim = 1;
          }
          k++;
        }

        if (is_delim == 1) {
          end_found = 1;
        } else {
          token_length++;
        }
      }

      result = token_start;

      if (i + token_length >= str_len) {
        saved_string = my_NULL;

      } else {
        string[i + token_length] = '\0';

        saved_string = string + i + token_length + 1;
      }
    }
  }

  return result;
}

void* my_to_upper(const char* str) {
  char* new_str = my_NULL;

  if (str != my_NULL) {
    my_size_t len = my_strlen(str);

    new_str = (char*)malloc((len + 1) * sizeof(char));

    if (new_str != my_NULL) {
      for (my_size_t i = 0; i < len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
          new_str[i] = str[i] - ('a' - 'A');
        } else {
          new_str[i] = str[i];
        }
      }
      new_str[len] = '\0';
    }
  }

  return (void*)new_str;
}

void* my_to_lower(const char* str) {
  char* new_str = my_NULL;
  if (str != my_NULL) {
    my_size_t len = my_strlen(str);
    new_str = (char*)malloc((len + 1) * sizeof(char));
    if (new_str != my_NULL) {
      for (my_size_t i = 0; i < len; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
          new_str[i] = str[i] + ('a' - 'A');
        } else {
          new_str[i] = str[i];
        }
      }
      new_str[len] = '\0';
    }
  }
  return (void*)new_str;
}

void* my_insert(const char* src, const char* str, my_size_t start_index) {
  char* new_str = my_NULL;
  if (src != my_NULL && str != my_NULL) {
    my_size_t src_len = my_strlen(src);
    my_size_t str_len = my_strlen(str);

    if (start_index <= src_len) {
      new_str = (char*)malloc((src_len + str_len + 1) * sizeof(char));
      if (new_str != my_NULL) {
        my_memcpy(new_str, src, start_index);
        my_memcpy(new_str + start_index, str, str_len);
        my_memcpy(new_str + start_index + str_len, src + start_index,
                  src_len - start_index);
        new_str[src_len + str_len] = '\0';
      }
    }
  }
  return (void*)new_str;
}

void* my_trim(const char* src, const char* trim_chars) {
  char* new_str = my_NULL;
  if (src != my_NULL && trim_chars != my_NULL) {
    my_size_t src_len = my_strlen(src);
    my_size_t start_index = 0;

    while (start_index < src_len && my_strchr(trim_chars, src[start_index])) {
      start_index++;
    }

    my_size_t end_index = src_len;
    while (end_index > start_index &&
           my_strchr(trim_chars, src[end_index - 1])) {
      end_index--;
    }

    my_size_t new_len = end_index - start_index;
    new_str = (char*)malloc((new_len + 1) * sizeof(char));
    if (new_str) {
      my_memcpy(new_str, src + start_index, new_len);
      new_str[new_len] = '\0';
    }
  }
  return (void*)new_str;
}

int my_sscanf(const char* str, const char* format, ...) {
  va_list args;
  va_start(args, format);

  int str_index = 0;
  int format_index = 0;

  int elements_sum = 0;

  if (str != NULL && format != NULL) {
    int error = 0;
    while (format[format_index] != '\0' && error == 0) {
      skip_space(format, &format_index);
      if (format[format_index] == '%') {
        format_index++;
        int limit = 0;
        int star_found = 0;
        char modifier = '\0';
        int element = 0;

        if (format[format_index] == '*') {
          star_found = 1;
          format_index++;
        }

        if (format[format_index] >= '0' && format[format_index] <= '9') {
          while (format[format_index] >= '0' && format[format_index] <= '9') {
            limit = limit * 10 + (format[format_index] - '0');
            format_index++;
          }
        }

        if (format[format_index] == 'l' || format[format_index] == 'L' ||
            format[format_index] == 'h') {
          modifier = format[format_index];
          format_index++;
        }

        int bracket_processed = 0;
        switch (format[format_index]) {
          case 'd':
            if (star_found) {
              process_long_int(str, &str_index, my_NULL, limit);

            } else {
              if (modifier == 'l') {
                element = process_long_int(str, &str_index,
                                           va_arg(args, long int*), limit);
              } else if (modifier == 'h') {
                element = process_short_int(str, &str_index,
                                            va_arg(args, short int*), limit);
              } else {
                element =
                    process_int(str, &str_index, va_arg(args, int*), limit);
              }

              elements_sum += element;
            }
            break;

          case 's':
            if (star_found) {
              process_string(str, &str_index, my_NULL, limit);

            } else {
              element =
                  process_string(str, &str_index, va_arg(args, char*), limit);
              elements_sum += element;
            }
            break;

          case 'c':
            if (star_found) {
              process_char(str, &str_index, my_NULL);

            } else {
              element = process_char(str, &str_index, va_arg(args, char*));
              elements_sum += element;
            }
            break;

          case 'f':
          case 'e':
          case 'E':
          case 'g':
          case 'G':
            if (star_found) {
              process_long_e(str, &str_index, my_NULL, limit);

            } else {
              if (modifier == 'l') {
                element = process_long_e(str, &str_index, va_arg(args, double*),
                                         limit);
              } else if (modifier == 'L') {
                element = process_long_long_e(
                    str, &str_index, va_arg(args, long double*), limit);
              } else {
                element =
                    process_e(str, &str_index, va_arg(args, float*), limit);
              }
              elements_sum += element;
            }
            break;

          case 'x':
          case 'X':
            if (star_found) {
              process_long_hex(str, &str_index, my_NULL, limit);

            } else {
              if (modifier == 'l') {
                element = process_long_hex(
                    str, &str_index, va_arg(args, unsigned long int*), limit);
              } else if (modifier == 'h') {
                element = process_short_hex(
                    str, &str_index, va_arg(args, unsigned short int*), limit);
              } else {
                element = process_hex(str, &str_index,
                                      va_arg(args, unsigned int*), limit);
              }
              elements_sum += element;
            }
            break;

          case 'o':
            if (star_found) {
              process_long_oct(str, &str_index, my_NULL, limit);

            } else {
              if (modifier == 'l') {
                element = process_long_oct(
                    str, &str_index, va_arg(args, unsigned long int*), limit);
              } else if (modifier == 'h') {
                element = process_short_oct(
                    str, &str_index, va_arg(args, unsigned short int*), limit);
              } else {
                element = process_oct(str, &str_index,
                                      va_arg(args, unsigned int*), limit);
              }
              elements_sum += element;
            }
            break;

          case 'u':
            if (star_found) {
              process_uns_long_int(str, &str_index, my_NULL, limit);

            } else {
              if (modifier == 'l') {
                element = process_uns_long_int(
                    str, &str_index, va_arg(args, unsigned long int*), limit);
              } else if (modifier == 'h') {
                element = process_uns_short_int(
                    str, &str_index, va_arg(args, unsigned short int*), limit);
              } else {
                element = process_uns_int(str, &str_index,
                                          va_arg(args, unsigned int*), limit);
              }
              elements_sum += element;
            }
            break;

          case 'i':
            if (star_found) {
              process_long_i(str, &str_index, my_NULL, limit);

            } else {
              if (modifier == 'l') {
                element = process_long_i(str, &str_index,
                                         va_arg(args, long int*), limit);
              } else if (modifier == 'h') {
                element = process_short_i(str, &str_index,
                                          va_arg(args, short int*), limit);
              } else {
                element = process_i(str, &str_index, va_arg(args, int*), limit);
              }
              elements_sum += element;
            }
            break;

          case 'p':
            if (star_found) {
              process_long_hex(str, &str_index, my_NULL, limit);

            } else {
              element =
                  process_pointer(str, &str_index, va_arg(args, void**), limit);
              elements_sum += element;
            }
            break;

          case 'n':
            if (!star_found) {
              int* result_n = va_arg(args, int*);

              if (result_n != NULL) {
                *result_n = str_index;
              }
            }
            break;

          case '%':
            if (str[str_index] == '%') {
              str_index++;
            }
            break;
          case '[':

            format_index++;

            const char* scanset_start = format + format_index;
            const char* closing_bracket = my_strchr(scanset_start, ']');

            if (closing_bracket != NULL) {
              int scanset_length = closing_bracket - scanset_start;
              char scanset_buffer[256] = {0};

              my_strncpy(scanset_buffer, scanset_start, scanset_length);

              int result = process_scanset(
                  str, &str_index, star_found ? NULL : va_arg(args, char*),
                  scanset_buffer, limit, star_found);

              if (!star_found) {
                elements_sum += result;
              }

              format_index += scanset_length;

              bracket_processed = 1;
            }

            if (!bracket_processed) {
              error = 1;
            }
            break;

          default:
            error = 1;
            break;
        }

        format_index++;

      } else {
        skip_space(str, &str_index);

        if (str[str_index] != format[format_index]) {
          error = 1;
        } else {
          format_index++;
          str_index++;
        }
      }
    }
  }
  va_end(args);

  return elements_sum;
}

void skip_space(const char* str, int* str_index) {
  while (str[*str_index] == ' ' || str[*str_index] == '\t' ||
         str[*str_index] == '\n' || str[*str_index] == '\r' ||
         str[*str_index] == '\v' || str[*str_index] == '\f') {
    (*str_index)++;
  }
}

int process_scanset(const char* str, int* str_index, char* output,
                    const char* scanset, int limit, int is_ignore) {
  int res = 0;

  if (str[*str_index] == '\0') {
    res = -1;
  } else {
    char lookup[256] = {0};
    const char* ptr = scanset;
    while (*ptr != '\0' && *ptr != ']') {
      if (ptr[0] == '-' && ptr != scanset && ptr[1] != '\0' && ptr[1] != ']') {
        unsigned char start = (unsigned char)ptr[-1];
        unsigned char end = (unsigned char)ptr[1];
        if (start <= end) {
          for (unsigned char c = start; c <= end; c++) {
            lookup[c] = 1;
          }
        }
        ptr += 2;
      } else {
        lookup[(unsigned char)*ptr] = 1;
        ptr++;
      }
    }
    int error = 0;
    int count = 0;
    while (str[*str_index] != '\0' && (limit == 0 || count < limit) &&
           error == 0) {
      unsigned char c = (unsigned char)str[*str_index];

      if (!lookup[c]) {
        error = 1;
      }

      if (error == 0) {
        if (!is_ignore && output != NULL) {
          output[count] = str[*str_index];
        }
        (*str_index)++;
        count++;

        if (!is_ignore && output != NULL) {
          output[count] = '\0';
        }

        if (is_ignore) {
          res = 0;
        } else {
          res = (count > 0) ? 1 : 0;
        }
      }
    }
  }
  return res;
}

int process_string(const char* str, int* str_index, char* result_str,
                   int limit) {
  int res = 0;
  if (str[*str_index] == '\0') {
    res = -1;
  } else {
    int result_index = 0;
    int max_length;

    if (limit == 0) {
      max_length = 1023;
    } else {
      max_length = limit;
    }

    skip_space(str, str_index);

    while (str[*str_index] != '\0' && str[*str_index] != ' ' &&
           str[*str_index] != '\t' && str[*str_index] != '\n' &&
           result_index < max_length) {
      if (result_str != my_NULL) {
        result_str[result_index] = str[(*str_index)];
      }
      result_index++;
      (*str_index)++;
    }
    if (result_str != my_NULL) {
      result_str[result_index] = '\0';
    }
    if (result_index > 0) {
      res = 1;
    }
  }
  return res;
}

int process_char(const char* str, int* str_index, char* result_char) {
  int res = -1;
  if (str != my_NULL) {
    if (str[*str_index] != '\0') {
      if (result_char != my_NULL) {
        *result_char = str[(*str_index)];
      }
      (*str_index)++;
      res = 1;
    }
  }
  return res;
}

int process_long_int(const char* str, int* str_index, long int* result_int,
                     int limit) {
  int res = 0;

  if (str[*str_index] == '\0') {
    res = -1;
  } else {
    skip_space(str, str_index);

    int is_negative = 0;
    if (str[*str_index] == '-') {
      is_negative = 1;
      (*str_index)++;
    }
    if (str[*str_index] == '+') {
      (*str_index)++;
    }

    char string_to_int[1024] = {0};
    int interim_index = 0;

    while (str[*str_index] >= '0' && str[*str_index] <= '9' &&
           interim_index < 1023 && (limit == 0 || interim_index < limit)) {
      string_to_int[interim_index] = str[*str_index];

      interim_index++;
      (*str_index)++;
    }
    string_to_int[interim_index] = '\0';

    if (interim_index > 0) {
      if (result_int != my_NULL) {
        long int value = 0;

        for (int i = 0; i < interim_index; i++) {
          value = value * 10 + (string_to_int[i] - '0');
        }

        if (is_negative) {
          value = -value;
        }
        *result_int = value;
      }
      res = 1;
    }
  }
  return res;
}

int process_int(const char* str, int* str_index, int* result_int, int limit) {
  int res = 0;
  long int result_tmp = 0;
  int func_res = process_long_int(str, str_index, &result_tmp, limit);
  if (func_res == 1) {
    if (result_int != my_NULL) {
      *result_int = (int)result_tmp;
    }
    res = 1;
  } else {
    res = func_res;
  }
  return res;
}

int process_short_int(const char* str, int* str_index, short int* result_int,
                      int limit) {
  int res = 0;
  long int result_tmp = 0;
  int func_res = process_long_int(str, str_index, &result_tmp, limit);
  if (func_res == 1) {
    if (result_int != my_NULL) {
      *result_int = (short int)result_tmp;
    }
    res = 1;
  }
  return res;
}

int process_long_hex(const char* str, int* str_index,
                     unsigned long int* result_hex, int limit) {
  int res = 0;
  if (str[*str_index] == '\0') {
    res = -1;
  } else {
    char string_to_hex[1024] = {0};
    int hex_index = 0;
    int chars_used = 0;

    skip_space(str, str_index);

    int has_prefix = 0;

    if (str[*str_index] == '0' &&
        (str[*str_index + 1] == 'x' || str[*str_index + 1] == 'X') &&
        (limit == 0 || chars_used < limit)) {
      has_prefix = 1;
      *str_index += 2;
      chars_used += 2;
    }

    while (((str[*str_index] >= '0' && str[*str_index] <= '9') ||
            (str[*str_index] >= 'a' && str[*str_index] <= 'f') ||
            (str[*str_index] >= 'A' && str[*str_index] <= 'F')) &&
           (limit == 0 || chars_used < limit)) {
      char c = str[*str_index];
      string_to_hex[hex_index] = c;
      hex_index++;
      (*str_index)++;
      chars_used++;
    }

    if (hex_index > 0 || has_prefix) {
      unsigned long int value = 0;

      int digits_to_process = hex_index;

      for (int i = 0; i < digits_to_process; i++) {
        char c = string_to_hex[i];
        unsigned long int digit = 0;

        if (c >= '0' && c <= '9') {
          digit = c - '0';
        } else if (c >= 'a' && c <= 'f') {
          digit = c - 'a' + 10;
        } else if (c >= 'A' && c <= 'F') {
          digit = c - 'A' + 10;
        }

        value = value * 16 + digit;
      }

      if (result_hex != my_NULL) {
        *result_hex = value;
      }
      res = 1;
    }
  }
  return res;
}

int process_hex(const char* str, int* str_index, unsigned int* result_hex,
                int limit) {
  int res = 0;
  unsigned long int result_tmp = 0;
  int func_res = process_long_hex(str, str_index, &result_tmp, limit);
  if (func_res == 1) {
    if (result_hex != my_NULL) {
      *result_hex = (unsigned int)result_tmp;
    }
    res = 1;
  }
  return res;
}

int process_short_hex(const char* str, int* str_index,
                      unsigned short int* result_hex, int limit) {
  int res = 0;
  unsigned long int result_tmp = 0;
  int func_res = process_long_hex(str, str_index, &result_tmp, limit);
  if (func_res == 1) {
    if (result_hex != my_NULL) {
      *result_hex = (unsigned short int)result_tmp;
    }
    res = 1;
  }
  return res;
}

int process_pointer(const char* str, int* str_index, void** result_ptr,
                    int limit) {
  int res = 0;
  unsigned long long value = 0;

  int digits_found = 0;
  int temp_index = *str_index;
  int temp_chars = 0;
  int has_prefix = 0;
  if (str[*str_index] == '\0') {
    res = -1;
  } else {
    skip_space(str, str_index);

    value = 0;
    digits_found = 0;
    temp_index = *str_index;
    temp_chars = 0;
    has_prefix = 0;

    if (limit <= 0) {
      limit = 2147483647;
    }

    if (limit >= 5 && my_strncmp(str + *str_index, "(nil)", 5) == 0) {
      *result_ptr = my_NULL;
      *str_index = *str_index + 5;
      res = 1;
    } else {
      if (limit >= 2 && str[temp_index] == '0' &&
          (str[temp_index + 1] == 'x' || str[temp_index + 1] == 'X')) {
        has_prefix = 1;
      }

      if (has_prefix) {
        temp_index += 2;
        temp_chars += 2;
      }

      int error = 0;
      while (temp_chars < limit && error == 0) {
        char c = str[temp_index];

        if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') ||
            (c >= 'A' && c <= 'F')) {
          unsigned int digit = 0;
          if (c >= '0' && c <= '9') {
            digit = c - '0';
          } else if (c >= 'a' && c <= 'f') {
            digit = c - 'a' + 10;
          } else if (c >= 'A' && c <= 'F') {
            digit = c - 'A' + 10;
          }

          value = value * 16 + digit;
          digits_found = 1;
          temp_index++;
          temp_chars++;
        } else {
          error = 1;
        }
      }

      if (digits_found) {
        *str_index = temp_index;
        *result_ptr = (void*)(uintptr_t)value;
        res = 1;
      }
    }
  }
  return res;
}

int process_uns_long_int(const char* str, int* str_index,
                         unsigned long int* result_uns_int, int limit) {
  unsigned long int value = 0;

  int res = 0;

  if (str[*str_index] == '\0') {
    res = -1;
  } else {
    skip_space(str, str_index);

    if (str[*str_index] != '-' && str[*str_index] != '+') {
      int digits_found = 0;
      int count = 0;
      while ((str[*str_index] >= '0' && str[*str_index] <= '9') &&
             (limit == 0 || count < limit)) {
        value = value * 10 + (str[*str_index] - '0');
        digits_found = 1;
        (*str_index)++;
        count++;
      }

      if (digits_found) {
        if (result_uns_int != my_NULL) {
          *result_uns_int = value;
        }
        res = 1;
      }
    }
  }
  return res;
}

int process_uns_short_int(const char* str, int* str_index,
                          unsigned short int* result_uns_int, int limit) {
  int res = 0;
  unsigned long int result_tmp = 0;
  int func_res = process_uns_long_int(str, str_index, &result_tmp, limit);
  if (func_res == 1) {
    if (result_uns_int != my_NULL) {
      *result_uns_int = (unsigned short int)result_tmp;
    }
    res = 1;

  } else {
    res = func_res;
  }
  return res;
}

int process_uns_int(const char* str, int* str_index,
                    unsigned int* result_uns_int, int limit) {
  int res = 0;
  unsigned long int result_tmp = 0;
  int func_res = process_uns_long_int(str, str_index, &result_tmp, limit);

  if (func_res == 1) {
    if (result_uns_int != my_NULL) {
      *result_uns_int = (unsigned int)result_tmp;
    }
    res = 1;

  } else {
    res = func_res;
  }
  return res;
}

int process_long_oct(const char* str, int* str_index,
                     unsigned long int* result_int, int limit) {
  int res = 0;

  if (str[*str_index] == '\0') {
    res = -1;
  } else {
    skip_space(str, str_index);
    char string_to_oct[1024] = {0};
    int interim_index = 0;
    while (str[*str_index] >= '0' && str[*str_index] <= '7' &&
           interim_index < 1023) {
      string_to_oct[interim_index] = str[*str_index];
      interim_index++;
      (*str_index)++;
    }
    string_to_oct[interim_index] = '\0';

    unsigned long int value = 0;
    int digits_found = 0;
    if (interim_index > 0) {
      digits_found = 1;
      if (limit == 0) {
        limit = interim_index;
      }
      if (limit > interim_index) {
        limit = interim_index;
      }

      for (int i = 0; i < limit; i++) {
        value = value * 8 + (string_to_oct[i] - '0');
      }
    }

    if (digits_found) {
      if (result_int != my_NULL) {
        *result_int = value;
      }
      res = 1;
    }
  }

  return res;
}

int process_short_oct(const char* str, int* str_index,
                      unsigned short int* result_int, int limit) {
  int res = 0;
  unsigned long int result_tmp = 0;
  int func_res = process_long_oct(str, str_index, &result_tmp, limit);
  if (func_res == 1) {
    if (result_int != my_NULL) {
      *result_int = (unsigned short int)result_tmp;
    }
    res = 1;
  } else {
    res = func_res;
  }
  return res;
}

int process_oct(const char* str, int* str_index, unsigned int* result_int,
                int limit) {
  int res = 0;
  unsigned long int result_tmp = 0;
  int func_res = process_long_oct(str, str_index, &result_tmp, limit);
  if (func_res == 1) {
    if (result_int != my_NULL) {
      *result_int = (unsigned int)result_tmp;
    }
    res = 1;
  } else {
    res = func_res;
  }
  return res;
}

int process_long_i(const char* str, int* str_index, long int* result_int,
                   int limit) {
  int res = 0;
  if (str[*str_index] == '\0') {
    res = -1;
  } else {
    int is_negative = 0;

    skip_space(str, str_index);

    if (str[*str_index] == '-') {
      is_negative = 1;
      (*str_index)++;
    } else if (str[*str_index] == '+') {
      (*str_index)++;
    }

    if (str[*str_index] == '0' &&
        (str[*str_index + 1] == 'x' || str[*str_index + 1] == 'X')) {
      unsigned long int hex_val = 0;
      res = process_long_hex(str, str_index, &hex_val, limit);
      if (res == 1 && result_int != my_NULL) {
        *result_int = is_negative ? -(long int)hex_val : (long int)hex_val;
      }
    } else if (str[*str_index] == '0') {
      unsigned long int oct_val = 0;
      res = process_long_oct(str, str_index, &oct_val, limit);
      if (res == 1 && result_int != my_NULL) {
        *result_int = is_negative ? -(long int)oct_val : (long int)oct_val;
      }
    } else {
      res = process_long_int(str, str_index, result_int, limit);
      if (res == 1 && is_negative && result_int != my_NULL) {
        *result_int = -(*result_int);
      }
    }
  }
  return res;
}

int process_i(const char* str, int* str_index, int* result_int, int limit) {
  int res = 0;
  long int result_tmp = 0;

  int func_res = process_long_i(str, str_index, &result_tmp, limit);

  if (func_res == 1) {
    if (result_int != my_NULL) {
      *result_int = (int)result_tmp;
    }
    res = 1;
  } else {
    res = func_res;
  }

  return res;
}

int process_short_i(const char* str, int* str_index, short int* result_short,
                    int limit) {
  int res = 0;
  long int result_tmp = 0;

  int func_res = process_long_i(str, str_index, &result_tmp, limit);

  if (func_res == 1) {
    if (result_short != my_NULL) {
      *result_short = (short int)result_tmp;
    }
    res = 1;
  } else {
    res = func_res;
  }

  return res;
}

int process_long_long_e(const char* str, int* str_index, long double* result,
                        int limit) {
  int res = 0;
  int start_index = *str_index;
  int chars_read = 0;

  if (str[*str_index] == '\0') {
    res = -1;
  } else {
    skip_space(str, str_index);
    int negative = 0;

    if ((limit == 0 || chars_read < limit) && str[*str_index] == '-') {
      negative = 1;
      (*str_index)++;
      chars_read++;
    } else if ((limit == 0 || chars_read < limit) && str[*str_index] == '+') {
      (*str_index)++;
      chars_read++;
    }

    if (str[*str_index] != '\0') {
      int inf_length = 3;
      if ((limit == 0 || chars_read + inf_length <= limit) &&
          my_strncmp(str + *str_index, "inf", 3) == 0) {
        if (result != my_NULL) {
          *result = my_INF_POS_LD;
        }
        *str_index += 3;
        chars_read += 3;

        int inity_length = 5;
        if ((limit == 0 || chars_read + inity_length <= limit) &&
            my_strncmp(str + *str_index, "inity", 5) == 0) {
          *str_index += 5;
          chars_read += 5;
        }
        if (negative && result != my_NULL) {
          *result = -(*result);
        }
        res = 1;

      } else if ((limit == 0 || chars_read + inf_length <= limit) &&
                 my_strncmp(str + *str_index, "INF", 3) == 0) {
        if (result != my_NULL) {
          *result = my_INF_POS_LD;
        }
        *str_index += 3;
        chars_read += 3;
        int inity_length = 5;
        if ((limit == 0 || chars_read + inity_length <= limit) &&
            my_strncmp(str + *str_index, "INITY", 5) == 0) {
          *str_index += 5;
          chars_read += 5;
        }
        if (negative && result != my_NULL) {
          *result = -(*result);
        }

        res = 1;
      } else if ((limit == 0 || chars_read + inf_length <= limit) &&
                 (my_strncmp(str + *str_index, "nan", 3) == 0 ||
                  my_strncmp(str + *str_index, "NAN", 3) == 0)) {
        if (result != my_NULL) {
          *result = my_NAN_LD;
        }
        *str_index += 3;
        chars_read += 3;
        if (negative && result != my_NULL) {
          *result = -(*result);
        }
        res = 1;
      }

      else {
        long double value = 0.0L;

        int digits_found = 0;

        while ((limit == 0 || chars_read < limit) && str[*str_index] >= '0' &&
               str[*str_index] <= '9') {
          value = value * 10.0 + (str[*str_index] - '0');

          digits_found++;
          (*str_index)++;
          chars_read++;
        }

        if ((limit == 0 || chars_read < limit) && str[*str_index] == '.') {
          (*str_index)++;
          chars_read++;
          long double fraction = 0.1;

          while ((limit == 0 || chars_read < limit) && str[*str_index] >= '0' &&
                 str[*str_index] <= '9') {
            value += (str[*str_index] - '0') * fraction;
            fraction *= 0.1;

            digits_found++;
            (*str_index)++;
            chars_read++;
          }
        }

        if (digits_found > 0) {
          if ((limit == 0 || chars_read < limit) &&
              (str[*str_index] == 'e' || str[*str_index] == 'E')) {
            int exp_start_index = *str_index + 1;
            int exp_sign = 1;
            int exp_val = 0;
            int exp_digits = 0;
            if ((limit == 0 || chars_read + 1 < limit)) {
              if (str[*str_index + 1] == '+') {
                (*str_index) += 2;
                chars_read += 2;
              } else if (str[*str_index + 1] == '-') {
                exp_sign = -1;
                (*str_index) += 2;
                chars_read += 2;
              } else {
                (*str_index)++;
                chars_read++;
              }
            } else {
              (*str_index)++;
              chars_read++;
            }

            while ((limit == 0 || chars_read < limit) &&
                   str[*str_index] >= '0' && str[*str_index] <= '9') {
              exp_val = exp_val * 10 + (str[*str_index] - '0');
              exp_digits++;
              (*str_index)++;
              chars_read++;
            }

            if (exp_digits == 0) {
              *str_index = exp_start_index - 1;
              chars_read = exp_start_index - start_index;
            } else {
              exp_val *= exp_sign;

              long double multiplier = 1.0;

              if (exp_val > 0) {
                for (int i = 0; i < exp_val; i++) {
                  multiplier *= 10.0;
                }
              } else if (exp_val < 0) {
                for (int i = 0; i < -exp_val; i++) {
                  multiplier /= 10.0;
                }
              }

              value *= multiplier;
            }
          }

          if (negative) {
            value = -value;
          }
          if (result != my_NULL) {
            *result = value;
          }
          res = 1;
        }
      }
    }

    if (res == 0 && *str_index > start_index) {
      *str_index = start_index;
    }
  }

  return res;
}

int process_long_e(const char* str, int* str_index, double* result_double,
                   int limit) {
  int res = 0;
  long double result_tmp = 0;
  int func_res = process_long_long_e(str, str_index, &result_tmp, limit);

  if (func_res == 1) {
    if (result_tmp != my_NAN_LD && result_tmp != my_INF_POS_LD &&
        result_tmp != my_INF_NEG_LD) {
      if (result_double != my_NULL) {
        *result_double = (double)result_tmp;
      }
      res = 1;
    } else {
      if (result_double != my_NULL) {
        *result_double = (double)result_tmp;
      }
      res = 1;
    }
  } else {
    res = func_res;
  }

  return res;
}

int process_e(const char* str, int* str_index, float* result_float, int limit) {
  int res = 0;
  long double result_tmp = 0;
  int func_res = process_long_long_e(str, str_index, &result_tmp, limit);

  if (func_res == 1) {
    if (result_tmp != my_NAN_LD && result_tmp != my_INF_POS_LD &&
        result_tmp != my_INF_NEG_LD) {
      if (result_float != my_NULL) {
        *result_float = (float)result_tmp;
      }
      res = 1;
    } else {
      if (result_float != my_NULL) {
        *result_float = (float)result_tmp;
      }
      res = 1;
    }
  } else {
    res = func_res;
  }
  return res;
}

int my_sprintf(char* str, const char* format, ...) {
  va_list args;
  va_start(args, format);

  int j = 0;
  int format_size = my_strlen(format);

  for (int i = 0; i < format_size; i++) {
    if (format[i] == '%') {
      i = parsing(str, format, i, &j, args);
    } else {
      str[j++] = format[i];
    }
  }
  str[j] = '\0';
  va_end(args);

  return j;
}

static int parsing(char* str, const char* format, int i, int* j, va_list args) {
  format_options opts = parse_format_options(format, &i);

  switch (format[i]) {
    case 'c':
      handle_char(str, j, args, opts);
      break;
    case 'd':
    case 'i':
      handle_int(str, j, args, opts);
      break;
    case 'e':
    case 'E':
      handle_float_eE(str, j, args, opts, format[i]);
      break;
    case 'f':
      handle_float_f(str, j, args, opts);
      break;
    case 'g':
    case 'G':
      handle_float_gG(str, j, args, opts, format[i]);
      break;
    case 'o':
      handle_unsigned_o(str, j, args, opts);
      break;
    case 's':
      handle_string(str, j, args, opts);
      break;
    case 'u':
      handle_unsigned_u(str, j, args, opts);
      break;
    case 'x':
    case 'X':
      handle_unsigned_xX(str, j, args, opts, format[i]);
      break;
    case 'p':
      handle_pointer(str, j, args, opts);
      break;
    case 'n':
      handle_count(j, args);
      break;
    case '%':
      handle_percent(str, j, opts);
      break;
    default:
      str[(*j)++] = format[i];
      break;
  }
  return i;
}

static format_options parse_format_options(const char* format, int* i) {
  format_options opts = {0, -1, 0, 0, 0, 0, 0};

  (*i)++;

  while (format[*i] != '\0') {
    switch (format[*i]) {
      case '-':
        opts.left_align = 1;
        opts.zero_pad = 0;
        break;
      case '+':
        opts.plus_sign = 1;
        break;
      case ' ':
        opts.space = 1;
        break;
      case '#':
        opts.alternate = 1;
        break;
      case '0':
        if (!opts.left_align) {
          opts.zero_pad = 1;
        }
        break;
      default:
        goto parse_width;
    }
    (*i)++;
  }

parse_width:
  while (format[*i] != '\0' && format[*i] >= '0' && format[*i] <= '9') {
    opts.width = opts.width * 10 + (format[*i] - '0');
    (*i)++;
  }

  if (format[*i] == '.') {
    (*i)++;
    opts.precision = 0;
    while (format[*i] != '\0' && format[*i] >= '0' && format[*i] <= '9') {
      opts.precision = opts.precision * 10 + (format[*i] - '0');
      (*i)++;
    }
  }

  return opts;
}

static void apply_width(char* str, int* j, format_options opts, int content_len,
                        int is_number) {
  if (opts.width > content_len) {
    int padding = opts.width - content_len;
    char pad_char = ' ';

    if (opts.zero_pad && !opts.left_align && is_number &&
        opts.precision == -1) {
      pad_char = '0';
    }

    if (opts.left_align) {
      for (int k = 0; k < padding; k++) {
        str[(*j)++] = ' ';
      }
    } else {
      for (int k = 0; k < padding; k++) {
        str[(*j)++] = pad_char;
      }
    }
  }
}

static void handle_char(char* str, int* j, va_list args, format_options opts) {
  char buffer[2];
  int content_len = 1;

  if (opts.width > content_len && !opts.left_align) {
    apply_width(str, j, opts, content_len, 0);
  }

  buffer[0] = (char)va_arg(args, int);
  buffer[1] = '\0';

  str[(*j)++] = buffer[0];

  if (opts.width > content_len && opts.left_align) {
    apply_width(str, j, opts, content_len, 0);
  }
}

static void handle_int(char* str, int* j, va_list args, format_options opts) {
  long num = va_arg(args, int);
  int negative = num < 0;
  if (negative) num = -num;

  char digits[INT_BUF_SIZE];
  int digit_count = 0;

  if (num == 0 && opts.precision != 0) {
    digits[digit_count++] = '0';
  } else if (num != 0) {
    digit_count = format_number_string(digits, num, 10, 0);
  }

  int total_digits = digit_count;
  if (opts.precision > digit_count) {
    total_digits = opts.precision;
  }

  int sign_len = 0;
  char sign_char = 0;
  if (negative) {
    sign_char = '-';
    sign_len = 1;
  } else if (opts.plus_sign) {
    sign_char = '+';
    sign_len = 1;
  } else if (opts.space) {
    sign_char = ' ';
    sign_len = 1;
  }

  int total_len = total_digits + sign_len;

  int use_zero_pad = opts.zero_pad && opts.precision == -1;

  if (!opts.left_align && opts.width > total_len) {
    if (use_zero_pad) {
      if (sign_char) {
        str[(*j)++] = sign_char;
      }
      for (int k = 0; k < opts.width - total_len; k++) {
        str[(*j)++] = '0';
      }
    } else {
      for (int k = 0; k < opts.width - total_len; k++) {
        str[(*j)++] = ' ';
      }
      if (sign_char) {
        str[(*j)++] = sign_char;
      }
    }
  } else {
    if (sign_char) {
      str[(*j)++] = sign_char;
    }
  }

  for (int k = 0; k < opts.precision - digit_count; k++) {
    str[(*j)++] = '0';
  }

  for (int k = 0; k < digit_count; k++) {
    str[(*j)++] = digits[k];
  }

  if (opts.left_align && opts.width > total_len) {
    for (int k = 0; k < opts.width - total_len; k++) {
      str[(*j)++] = ' ';
    }
  }
}

static void handle_unsigned_u(char* str, int* j, va_list args,
                              format_options opts) {
  unsigned long num = va_arg(args, unsigned int);

  char digits[INT_BUF_SIZE];
  int digit_count = 0;

  if (num == 0 && opts.precision != 0) {
    digits[digit_count++] = '0';
  } else if (num != 0) {
    digit_count = format_unsigned_string(digits, num, 10, 0);
  }

  int total_digits = digit_count;
  if (opts.precision > digit_count) {
    total_digits = opts.precision;
  }

  int use_zero_pad = opts.zero_pad && opts.precision == -1;

  if (!opts.left_align && opts.width > total_digits) {
    if (use_zero_pad) {
      for (int k = 0; k < opts.width - total_digits; k++) {
        str[(*j)++] = '0';
      }
    } else {
      for (int k = 0; k < opts.width - total_digits; k++) {
        str[(*j)++] = ' ';
      }
    }
  }

  for (int k = 0; k < opts.precision - digit_count; k++) {
    str[(*j)++] = '0';
  }

  for (int k = 0; k < digit_count; k++) {
    str[(*j)++] = digits[k];
  }

  if (opts.left_align && opts.width > total_digits) {
    for (int k = 0; k < opts.width - total_digits; k++) {
      str[(*j)++] = ' ';
    }
  }
}

static void handle_unsigned_o(char* str, int* j, va_list args,
                              format_options opts) {
  char buffer[INT_BUF_SIZE];
  int index = 0;

  unsigned long num = va_arg(args, unsigned int);

  if (num == 0 && opts.precision == 0) {
    if (opts.alternate) {
      buffer[index++] = '0';
    } else {
      buffer[index++] = '\0';
    }
  } else if (num == 0) {
    buffer[index++] = '0';
  } else {
    index = format_unsigned_string(buffer, num, 8, 0);
  }

  int num_digits = index;
  if (opts.precision > num_digits) {
    int zeros_to_add = opts.precision - num_digits;
    for (int i = index - 1; i >= 0; i--) {
      buffer[i + zeros_to_add] = buffer[i];
    }
    for (int i = 0; i < zeros_to_add; i++) {
      buffer[i] = '0';
    }
    index += zeros_to_add;
  }

  if (opts.alternate && buffer[0] != '0' && index > 0) {
    for (int i = index; i > 0; i--) {
      buffer[i] = buffer[i - 1];
    }
    buffer[0] = '0';
    index++;
  }

  if (opts.width > index && !opts.left_align) {
    apply_width(str, j, opts, index, 1);
  }

  for (int k = 0; k < index; k++) {
    str[(*j)++] = buffer[k];
  }

  if (opts.width > index && opts.left_align) {
    apply_width(str, j, opts, index, 1);
  }
}

static void handle_unsigned_xX(char* str, int* j, va_list args,
                               format_options opts, char specifier) {
  char buffer[INT_BUF_SIZE];
  int index = 0;
  int uppercase = (specifier == 'X');

  unsigned long num = va_arg(args, unsigned int);

  if (num == 0 && opts.precision == 0) {
    buffer[index++] = '\0';
  } else if (num == 0) {
    buffer[index++] = '0';
  } else {
    index = format_unsigned_string(buffer, num, 16, uppercase);
  }

  int num_digits = index;
  if (opts.precision > num_digits) {
    int zeros_to_add = opts.precision - num_digits;
    for (int i = index - 1; i >= 0; i--) {
      buffer[i + zeros_to_add] = buffer[i];
    }
    for (int i = 0; i < zeros_to_add; i++) {
      buffer[i] = '0';
    }
    index += zeros_to_add;
  }

  int prefix_len = 0;
  if (opts.alternate && num != 0) {
    prefix_len = 2;
  }

  if (opts.width > index + prefix_len && !opts.left_align) {
    apply_width(str, j, opts, index + prefix_len, 1);
  }

  if (opts.alternate && num != 0) {
    str[(*j)++] = '0';
    str[(*j)++] = uppercase ? 'X' : 'x';
  }

  for (int k = 0; k < index; k++) {
    str[(*j)++] = buffer[k];
  }

  if (opts.width > index + prefix_len && opts.left_align) {
    apply_width(str, j, opts, index + prefix_len, 1);
  }
}

static void handle_string(char* str, int* j, va_list args,
                          format_options opts) {
  char* s = va_arg(args, char*);
  if (!s) s = "(null)";

  int len = my_strlen(s);
  if (opts.precision >= 0 && opts.precision < len) {
    len = opts.precision;
  }

  if (!opts.left_align && opts.width > len) {
    for (int k = 0; k < opts.width - len; k++) {
      str[(*j)++] = ' ';
    }
  }

  for (int k = 0; k < len; k++) {
    str[(*j)++] = s[k];
  }

  if (opts.left_align && opts.width > len) {
    for (int k = 0; k < opts.width - len; k++) {
      str[(*j)++] = ' ';
    }
  }
}

static void handle_float_f(char* str, int* j, va_list args,
                           format_options opts) {
  double num = va_arg(args, double);
  int actual_precision = (opts.precision == -1) ? 6 : opts.precision;

  if (num != num) {
    char* nan_str = "nan";
    int len = 3;
    if (opts.width > len && !opts.left_align) {
      apply_width(str, j, opts, len, 0);
    }
    for (int i = 0; i < len; i++) str[(*j)++] = nan_str[i];
    if (opts.width > len && opts.left_align) {
      apply_width(str, j, opts, len, 0);
    }
    return;
  } else if (num == 1.0 / 0.0) {
    char* inf_str = "inf";
    int len = 3;
    if (opts.width > len && !opts.left_align) {
      apply_width(str, j, opts, len, 0);
    }
    for (int i = 0; i < len; i++) str[(*j)++] = inf_str[i];
    if (opts.width > len && opts.left_align) {
      apply_width(str, j, opts, len, 0);
    }
    return;
  } else if (num == -1.0 / 0.0) {
    char* inf_str = "-inf";
    int len = 4;
    if (opts.width > len && !opts.left_align) {
      apply_width(str, j, opts, len, 0);
    }
    for (int i = 0; i < len; i++) str[(*j)++] = inf_str[i];
    if (opts.width > len && opts.left_align) {
      apply_width(str, j, opts, len, 0);
    }
    return;
  }

  double rounding = 0.5;
  for (int i = 0; i < actual_precision; i++) {
    rounding /= 10.0;
  }

  if (num >= 0) {
    num += rounding;
  } else {
    num -= rounding;
  }

  int negative = num < 0;
  if (negative) num = -num;

  char temp_buffer[128];
  int temp_index = 0;

  int has_sign = 0;
  if (negative) {
    temp_buffer[temp_index++] = '-';
    has_sign = 1;
  } else if (opts.plus_sign) {
    temp_buffer[temp_index++] = '+';
    has_sign = 1;
  } else if (opts.space) {
    temp_buffer[temp_index++] = ' ';
    has_sign = 1;
  }

  long int_part = (long)num;
  double frac_part = num - int_part;

  if (int_part == 0) {
    temp_buffer[temp_index++] = '0';
  } else {
    char int_digits[INT_BUF_SIZE];
    int int_count = 0;
    long temp = int_part;

    do {
      int_digits[int_count++] = '0' + temp % 10;
      temp /= 10;
    } while (temp > 0);

    for (int k = int_count - 1; k >= 0; k--) {
      temp_buffer[temp_index++] = int_digits[k];
    }
  }

  if (actual_precision > 0) {
    temp_buffer[temp_index++] = '.';

    for (int k = 0; k < actual_precision; k++) {
      frac_part *= 10.0;
      int digit = (int)frac_part;
      temp_buffer[temp_index++] = '0' + digit;
      frac_part -= digit;
    }
  }

  if (opts.width > temp_index && !opts.left_align && opts.zero_pad) {
    for (int k = 0; k < has_sign; k++) {
      str[(*j)++] = temp_buffer[k];
    }

    int padding = opts.width - temp_index;
    for (int k = 0; k < padding; k++) {
      str[(*j)++] = '0';
    }

    for (int k = has_sign; k < temp_index; k++) {
      str[(*j)++] = temp_buffer[k];
    }
  } else {
    if (opts.width > temp_index && !opts.left_align) {
      apply_width(str, j, opts, temp_index, 1);
    }

    for (int k = 0; k < temp_index; k++) {
      str[(*j)++] = temp_buffer[k];
    }

    if (opts.width > temp_index && opts.left_align) {
      apply_width(str, j, opts, temp_index, 1);
    }
  }
}

static void handle_float_eE(char* str, int* j, va_list args,
                            format_options opts, char specifier) {
  double num = va_arg(args, double);
  char buffer[EXP_BUF_SIZE];
  int index = 0;

  char exp_char = (specifier == 'E') ? 'E' : 'e';

  handle_float_special_cases(num, buffer, &index, specifier);
  if (index > 0) {
    if (opts.width > index && !opts.left_align) {
      apply_width(str, j, opts, index, 0);
    }
    for (int k = 0; k < index; k++) {
      str[(*j)++] = buffer[k];
    }
    if (opts.width > index && opts.left_align) {
      apply_width(str, j, opts, index, 0);
    }
    return;
  }

  int negative = 0;
  if (num < 0) {
    negative = 1;
    num = -num;
  }

  int actual_precision = (opts.precision == -1) ? 6 : opts.precision;

  int exponent = 0;
  if (num != 0.0) {
    double temp = num;
    while (temp >= 10.0) {
      temp /= 10.0;
      exponent++;
    }
    while (temp < 1.0 && temp > 0.0) {
      temp *= 10.0;
      exponent--;
    }
    num = temp;
  }

  char num_buffer[128];
  int num_index = 0;

  if (negative) {
    num_buffer[num_index++] = '-';
  } else if (opts.plus_sign) {
    num_buffer[num_index++] = '+';
  } else if (opts.space) {
    num_buffer[num_index++] = ' ';
  }

  int int_part = (int)num;
  num_buffer[num_index++] = '0' + int_part;
  num -= int_part;

  if (actual_precision >= 0) {
    num_buffer[num_index++] = '.';

    int extra_digits[actual_precision + 2];
    for (int k = 0; k < actual_precision + 1; k++) {
      num *= 10.0;
      extra_digits[k] = (int)num;
      num -= extra_digits[k];
    }

    if (extra_digits[actual_precision] >= 5) {
      int carry = 1;
      for (int k = actual_precision - 1; k >= 0; k--) {
        extra_digits[k] += carry;
        carry = extra_digits[k] / 10;
        extra_digits[k] %= 10;
        if (carry == 0) break;
      }
      if (carry > 0) {
        int_part++;
        num_buffer[negative + (opts.plus_sign || opts.space ? 1 : 0)] =
            '0' + int_part;
        if (int_part == 10) {
          num_buffer[negative + (opts.plus_sign || opts.space ? 1 : 0)] = '1';
          exponent++;
          for (int k = 0; k < actual_precision; k++) {
            extra_digits[k] = 0;
          }
        }
      }
    }

    for (int k = 0; k < actual_precision; k++) {
      num_buffer[num_index++] = '0' + extra_digits[k];
    }
  }

  num_buffer[num_index++] = exp_char;
  num_buffer[num_index++] = (exponent >= 0) ? '+' : '-';

  int exp_abs = (exponent < 0) ? -exponent : exponent;
  if (exp_abs < 10) {
    num_buffer[num_index++] = '0';
    num_buffer[num_index++] = '0' + exp_abs;
  } else {
    num_buffer[num_index++] = '0' + exp_abs / 10;
    num_buffer[num_index++] = '0' + exp_abs % 10;
  }

  if (opts.width > num_index && !opts.left_align) {
    apply_width(str, j, opts, num_index, 1);
  }
  for (int k = 0; k < num_index; k++) {
    str[(*j)++] = num_buffer[k];
  }
  if (opts.width > num_index && opts.left_align) {
    apply_width(str, j, opts, num_index, 1);
  }
}

static void handle_float_gG(char* str, int* j, va_list args,
                            format_options opts, char specifier) {
  double num = va_arg(args, double);
  int actual_precision = (opts.precision == -1) ? 6 : opts.precision;
  if (actual_precision == 0) actual_precision = 1;
  int uppercase = (specifier == 'G');

  if (num != num) {
    char* nan_str = uppercase ? "NAN" : "nan";
    for (int i = 0; nan_str[i] != '\0'; i++) str[(*j)++] = nan_str[i];
    return;
  } else if (num == 1.0 / 0.0) {
    char* inf_str = uppercase ? "INF" : "inf";
    for (int i = 0; inf_str[i] != '\0'; i++) str[(*j)++] = inf_str[i];
    return;
  } else if (num == -1.0 / 0.0) {
    char* inf_str = uppercase ? "-INF" : "-inf";
    for (int i = 0; inf_str[i] != '\0'; i++) str[(*j)++] = inf_str[i];
    return;
  }

  double abs_num = num < 0 ? -num : num;

  int use_exp = 0;
  if (abs_num >= 1e6 || (abs_num > 0 && abs_num < 1e-4)) {
    use_exp = 1;
  }

  if (use_exp) {
    char exp_char = uppercase ? 'E' : 'e';
    int exponent = 0;

    double normalized = abs_num;
    if (normalized != 0.0) {
      while (normalized >= 10.0) {
        normalized /= 10.0;
        exponent++;
      }
      while (normalized < 1.0) {
        normalized *= 10.0;
        exponent--;
      }
    }

    double round_factor = 0.5;
    for (int i = 0; i < actual_precision; i++) {
      round_factor /= 10.0;
    }
    normalized += round_factor;

    if (normalized >= 10.0) {
      normalized /= 10.0;
      exponent++;
    }

    if (num < 0) {
      str[(*j)++] = '-';
    }

    char temp_buffer[128];
    int temp_index = 0;

    int int_part = (int)normalized;
    temp_buffer[temp_index++] = '0' + int_part;
    normalized -= int_part;

    if (actual_precision > 1) {
      temp_buffer[temp_index++] = '.';

      int digits_to_add = actual_precision - 1;
      for (int k = 0; k < digits_to_add; k++) {
        normalized *= 10.0;
        int digit = (int)normalized;
        temp_buffer[temp_index++] = '0' + digit;
        normalized -= digit;
      }

      while (temp_index > 1 && temp_buffer[temp_index - 1] == '0') {
        temp_index--;
      }
      if (temp_buffer[temp_index - 1] == '.') {
        temp_index--;
      }
    }

    for (int k = 0; k < temp_index; k++) {
      str[(*j)++] = temp_buffer[k];
    }

    str[(*j)++] = exp_char;
    str[(*j)++] = (exponent >= 0) ? '+' : '-';

    int exp_abs = (exponent < 0) ? -exponent : exponent;
    if (exp_abs < 10) {
      str[(*j)++] = '0';
      str[(*j)++] = '0' + exp_abs;
    } else {
      char exp_buf[10];
      int exp_len = 0;
      int temp = exp_abs;
      do {
        exp_buf[exp_len++] = '0' + temp % 10;
        temp /= 10;
      } while (temp > 0);
      for (int k = exp_len - 1; k >= 0; k--) {
        str[(*j)++] = exp_buf[k];
      }
    }
  } else {
    int negative = num < 0;
    if (negative) num = -num;

    char temp_buffer[128];
    int temp_index = 0;

    int has_sign = 0;
    if (negative) {
      temp_buffer[temp_index++] = '-';
      has_sign = 1;
    } else if (opts.plus_sign) {
      temp_buffer[temp_index++] = '+';
      has_sign = 1;
    } else if (opts.space) {
      temp_buffer[temp_index++] = ' ';
      has_sign = 1;
    }

    long int_part = (long)num;
    double frac_part = num - int_part;

    double rounding = 0.5;
    for (int i = 0; i < actual_precision; i++) {
      rounding /= 10.0;
    }
    frac_part += rounding;

    if (frac_part >= 1.0) {
      int_part++;
      frac_part -= 1.0;
    }

    if (int_part == 0) {
      temp_buffer[temp_index++] = '0';
    } else {
      char int_digits[INT_BUF_SIZE];
      int int_count = 0;
      long temp = int_part;

      do {
        int_digits[int_count++] = '0' + temp % 10;
        temp /= 10;
      } while (temp > 0);

      for (int k = int_count - 1; k >= 0; k--) {
        temp_buffer[temp_index++] = int_digits[k];
      }
    }

    if (actual_precision > 0) {
      char frac_digits[64];
      int frac_count = 0;
      int last_non_zero = -1;

      for (int k = 0; k < actual_precision; k++) {
        frac_part *= 10.0;
        int digit = (int)frac_part;
        frac_digits[frac_count++] = '0' + digit;
        if (digit != 0) last_non_zero = frac_count - 1;
        frac_part -= digit;

        if (frac_part < 1e-10) break;
      }

      if (last_non_zero >= 0) {
        temp_buffer[temp_index++] = '.';
        for (int k = 0; k <= last_non_zero; k++) {
          temp_buffer[temp_index++] = frac_digits[k];
        }
      }
    }

    if (opts.width > temp_index && !opts.left_align && opts.zero_pad) {
      for (int k = 0; k < has_sign; k++) {
        str[(*j)++] = temp_buffer[k];
      }

      int padding = opts.width - temp_index;
      for (int k = 0; k < padding; k++) {
        str[(*j)++] = '0';
      }

      for (int k = has_sign; k < temp_index; k++) {
        str[(*j)++] = temp_buffer[k];
      }
    } else {
      if (opts.width > temp_index && !opts.left_align) {
        apply_width(str, j, opts, temp_index, 1);
      }

      for (int k = 0; k < temp_index; k++) {
        str[(*j)++] = temp_buffer[k];
      }

      if (opts.width > temp_index && opts.left_align) {
        apply_width(str, j, opts, temp_index, 1);
      }
    }
  }
}

static void handle_pointer(char* str, int* j, va_list args,
                           format_options opts) {
  void* ptr = va_arg(args, void*);

  if (ptr == NULL) {
#ifdef __APPLE__
    const char* nil_str = "0x0";
    int len = 3;
#else
    const char* nil_str = "(nil)";
    int len = 5;
#endif

    if (opts.width > len && !opts.left_align) {
      apply_width(str, j, opts, len, 0);
    }

    for (int k = 0; k < len; k++) {
      str[(*j)++] = nil_str[k];
    }

    if (opts.width > len && opts.left_align) {
      apply_width(str, j, opts, len, 0);
    }
  } else {
    uintptr_t ptr_value = (uintptr_t)ptr;
    char buffer[20];
    int index = 0;

    index = format_unsigned_string(buffer, ptr_value, 16, 0);

    char hex_str[22] = "0x";
    for (int k = 0; k < index; k++) {
      hex_str[k + 2] = buffer[k];
    }
    int total_len = index + 2;
    hex_str[total_len] = '\0';

    if (opts.width > total_len && !opts.left_align) {
      apply_width(str, j, opts, total_len, 0);
    }

    for (int k = 0; k < total_len; k++) {
      str[(*j)++] = hex_str[k];
    }

    if (opts.width > total_len && opts.left_align) {
      apply_width(str, j, opts, total_len, 0);
    }
  }
}

static void handle_count(int* j, va_list args) {
  int* count_ptr = va_arg(args, int*);
  if (count_ptr != NULL) {
    *count_ptr = *j;
  }
}

static void handle_percent(char* str, int* j, format_options opts) {
  if (opts.width > 1 && !opts.left_align) {
    apply_width(str, j, opts, 1, 0);
  }
  str[(*j)++] = '%';
  if (opts.width > 1 && opts.left_align) {
    apply_width(str, j, opts, 1, 0);
  }
}

static int format_number_string(char* buffer, long num, int base,
                                int uppercase) {
  int index = 0;
  const char* digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";

  if (num == 0) {
    buffer[index++] = '0';
  } else {
    while (num > 0) {
      buffer[index++] = digits[num % base];
      num /= base;
    }
    reverse_buffer(buffer, index);
  }
  return index;
}

static int format_unsigned_string(char* buffer, unsigned long num, int base,
                                  int uppercase) {
  int index = 0;
  const char* digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";

  if (num == 0) {
    buffer[index++] = '0';
  } else {
    while (num > 0) {
      buffer[index++] = digits[num % base];
      num /= base;
    }
    reverse_buffer(buffer, index);
  }
  return index;
}

static void handle_float_special_cases(double num, char* buffer, int* index,
                                       char specifier) {
  int uppercase = (specifier == 'E' || specifier == 'G');
  const char* str = NULL;

  if (num != num) {
    str = uppercase ? "NAN" : "nan";
    *index = 3;
  } else if (num == 1.0 / 0.0) {
    str = uppercase ? "INF" : "inf";
    *index = 3;
  } else if (num == -1.0 / 0.0) {
    str = uppercase ? "-INF" : "-inf";
    *index = 4;
  }

  if (str != NULL) {
    for (int i = 0; str[i] != '\0'; i++) {
      buffer[i] = str[i];
    }
  }
}

static void reverse_buffer(char* buffer, int length) {
  for (int i = 0, j = length - 1; i < j; i++, j--) {
    char temp = buffer[i];
    buffer[i] = buffer[j];
    buffer[j] = temp;
  }
}