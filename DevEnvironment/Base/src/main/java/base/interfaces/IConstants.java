package base.interfaces;

import java.nio.charset.Charset;
import java.nio.charset.StandardCharsets;

/**
 * The IConstants interface defines constants of the base library.
 */
public interface IConstants {
  /**
   * The version of the configuration.
   */
  double ConfigurationVersion = 1.0;

  /**
   * The default encoding.
   */
  Charset DefaultEncoding = StandardCharsets.UTF_8;
}
