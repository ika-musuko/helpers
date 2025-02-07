function objectMap(obj, func) {
  return Object.fromEntries(
    Object.entries(obj)
    .map(
      ([key, value]) => [key, func(value)]
    )
  );
}
