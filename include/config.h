
#ifndef PROJECT_INCLUDES_CONFIG_H
#define PROJECT_INCLUDES_CONFIG_H

#ifndef __GNUC__
#define ATTRIBUTES(attrs)
#else
#define ATTRIBUTES(attrs) __attribute__(attrs)
#endif

#endif /** PROJECT_INCLUDES_CONFIG_H */
